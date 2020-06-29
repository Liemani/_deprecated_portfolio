//
//  MoveNode.swift
//  GrowDungeon
//
//  Created by 박정훈 on 08/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

struct TouchProcessor {
    
    static var camera: SKCameraNode!
    
    enum TouchCondition {
        case none
        case dragging
        case touchedUIButton
        case touchedNode
        case touchedLink
    }
    
    private static var lastTouchPoint: CGPoint!
    static var touchCondition: TouchCondition = .none
    
    static var touchingObject: SKSpriteNode!
    static var touchingLinkPoint: CGPoint!
    
    static var isAnimating: Bool = false
    
    static func initCamera(_ camera: SKCameraNode) {
        self.camera = camera
    }
    
    /// 터치가 시작되면 실행한다
    static func toucheBegan(_ touchPoint: CGPoint) {
        // 버튼 터치
        if SceneView.uiLayer.children[0].contains(touchPoint) {
            AudioManager.playShortAudio(name: PList.Name.Key.button)
            UIController.turnIsEditMode()
        } else if SceneView.uiLayer.children[1].contains(touchPoint) {
            // isRoom 버튼 터치
            AudioManager.playShortAudio(name: PList.Name.Key.button)
            UIController.turnIsMakeRoomMode()
        } else if UIData.isEditMode {
            investigateTouchedObject(touchPoint: touchPoint)
        } else {
            startDragging(touchPoint: touchPoint)
        }
    }
    /// 어떤 오브젝트를 터치했는가 조사한다
    static func investigateTouchedObject(touchPoint: CGPoint) {
        let touchPointInMovingLayer: CGPoint = CGPoint(x: touchPoint.x + camera.position.x, y: touchPoint.y + camera.position.y)
        let nodeS = SceneView.nodeLayer.nodes(at: CGPoint(x: touchPointInMovingLayer.x,
                                                                y: touchPointInMovingLayer.y))
        
        var linkS: [SKNode] = []
        for linkNode in SceneView.linkLayer.children {
            if let spriteNode = linkNode as? SKSpriteNode {
                let symmetricalTranspositionPoint = CGPoint(x: touchPointInMovingLayer.x - spriteNode.position.x,
                                                            y: touchPointInMovingLayer.y - spriteNode.position.y)
                let theta = -spriteNode.zRotation
                let xPosition = symmetricalTranspositionPoint.x * cos(theta) - symmetricalTranspositionPoint.y * sin(theta)
                let yPosition = symmetricalTranspositionPoint.x * sin(theta) + symmetricalTranspositionPoint.y * cos(theta)
                let resultPoint = CGPoint(x: xPosition, y: yPosition)
                
                let halfOfWidth = spriteNode.size.width / 2
                let halfOfHeight = spriteNode.size.height / 2
                
                if -halfOfWidth < resultPoint.x &&
                    resultPoint.x < halfOfWidth &&
                    -halfOfHeight < resultPoint.y &&
                    resultPoint.y < halfOfHeight {
                    linkS.append(linkNode)
                    
                    let beforReverseTranspositionPoint: CGPoint = CGPoint(x: 0, y: resultPoint.y)
                    let anotherTheta = linkNode.zRotation
                    let rotationTransFormationPoint: CGPoint = CGPoint(x: beforReverseTranspositionPoint.x * cos(anotherTheta) - beforReverseTranspositionPoint.y * sin(anotherTheta),
                                                                       y: beforReverseTranspositionPoint.x * sin(anotherTheta) + beforReverseTranspositionPoint.y * cos(anotherTheta))
                    let anotherResultPoint: CGPoint = CGPoint(x: rotationTransFormationPoint.x + spriteNode.position.x,
                                                              y: rotationTransFormationPoint.y + spriteNode.position.y)
                    touchingLinkPoint = anotherResultPoint
                }
            }
        }
        
        if !nodeS.isEmpty {
            touchCondition = .touchedNode
            touchingObject = nodeS.first as? SKSpriteNode
        } else if !linkS.isEmpty {
            touchCondition = .touchedLink
            touchingObject = linkS.first as? SKSpriteNode
        } else {
            startDragging(touchPoint: touchPoint)
        }
    }
    /// 화면 드래그 시작
    static func startDragging(touchPoint: CGPoint) {
        lastTouchPoint = touchPoint
        touchCondition = .dragging
        if CameraController.isAnimating {
            CameraController.stopAnimating()
        }
    }
    /// 터치가 움직인다
    static func touchMoved(point: CGPoint) {
        switch TouchProcessor.touchCondition {
        case .dragging:
            TouchProcessor.node(with: point)
        case .touchedNode, .touchedLink:
            if !SceneView.isDrawingPreview {
                SceneView.initTempNode(looking: point)
            } else {
                SceneView.drawPreview(tracking: point)
            }
        default: break
        }
    }
    
    /// 터치가 끝나면
    static func touchEnded() {
        // 무빙노드가 범위 밖이면 애니메이션을 참으로
        switch touchCondition {
        case .dragging:
            if !GameVariable.movableRangeWithoutRestriction.contains(camera.position) {
                isAnimating = true
            }
        case .touchedNode:
            let point = UIData.doBuildRoom ? SceneView.tempRoomNode.position : SceneView.tempJointNode.position
            DungeonController.addLMNodeFrom(spriteNode: TouchProcessor.touchingObject, location: point)
            SceneView.endDrawing()
        case .touchedLink:
            let point = UIData.doBuildRoom ? SceneView.tempRoomNode.position : SceneView.tempJointNode.position
            DungeonController.addLMNodeFromLink(to: point)
            SceneView.endDrawing()
        default: break
        }
        touchCondition = .none
    }
    /// 주어진 터치 포인트를 사용하여 카메라 위치와 씬컨트롤러의 무빙레이어를 이동시키는 함수
    static func node(with currentTouchPoint: CGPoint) {
        // x, y 변화량 계산
        let dx = currentTouchPoint.x - lastTouchPoint.x
        let dy = currentTouchPoint.y - lastTouchPoint.y
        // 카메라 위치에 따른 변화 처리
        if GameVariable.movableRangeWithoutRestriction.xRange.contains(camera.position.x) {
            camera.position.x -= dx
        } else {
            camera.position.x -= dx / PList.Size.restriction.width
        }
        if GameVariable.movableRangeWithoutRestriction.yRange.contains(camera.position.y) {
            camera.position.y -= dy
        } else {
            camera.position.y -= dy / PList.Size.restriction.height
        }
        
        lastTouchPoint = currentTouchPoint
    }
    /// 카메라 포지션에서 가장 가까운 무버블윋아웃레스트릭션 범위 안의 포인트를 찾는 함수
    static func findNearestInnerPoint() -> CGPoint {
        let xPosition: CGFloat
        let yPosition: CGFloat
        
        if camera.position.x < GameVariable.movableRangeWithoutRestriction.xRange.lowerBound {
            xPosition = GameVariable.movableRangeWithoutRestriction.xRange.lowerBound
        } else if camera.position.x > GameVariable.movableRangeWithoutRestriction.xRange.upperBound {
            xPosition = GameVariable.movableRangeWithoutRestriction.xRange.upperBound
        } else {
            xPosition = camera.position.x
        }
        if camera.position.y < GameVariable.movableRangeWithoutRestriction.yRange.lowerBound {
            yPosition = GameVariable.movableRangeWithoutRestriction.yRange.lowerBound
        } else if camera.position.y > GameVariable.movableRangeWithoutRestriction.yRange.upperBound {
            yPosition = GameVariable.movableRangeWithoutRestriction.yRange.upperBound
        } else {
            yPosition = camera.position.y
        }
        return CGPoint(x: xPosition, y: yPosition)
    }
    
}
