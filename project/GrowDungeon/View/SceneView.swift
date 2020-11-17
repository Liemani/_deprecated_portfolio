//
//  SetInitialScene.swift
//  GrowDungeon
//
//  Created by 박정훈 on 08/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

struct SceneView {
    
    static var rootNode: SKScene!           // rootNode
    static var camera: SKCameraNode!        // children[0]
    static var uiLayer: SKNode!             // children[0][0]
    static var drawLayer: SKNode!           // children[1]
    static var nodeLayer: SKNode!           // children[1][0]
    static var linkLayer: SKNode!           // children[1][1]
    static var backgroundLayer: SKNode!     // children[1][2]
    
    /// 씬 초기화 : 원래 프라이벳이 위로 가는걸 좋아하지만 다른 프라이벳 메서드들이 단 한 곳에서만 쓰이는 것들이기에 순차적으로 배치하였다
    static func initScene(rootNode: SKScene) {
        self.rootNode = rootNode
        initLayerSToRootNode()
        setLayerInitialState()
        
        UIController.initUILayer()
        initDrawLayer()
    }
    /// 레이어들을 순차적으로 addChild 한다
    private static func initLayerSToRootNode() {
        camera = rootNode.camera
        
        let uiLayer = SKNode()
        camera.addChild(uiLayer)
        self.uiLayer = uiLayer
        
        let drawLayer = SKNode()
        rootNode.addChild(drawLayer)
        self.drawLayer = drawLayer
        
        let nodeLayer = SKNode()
        drawLayer.addChild(nodeLayer)
        self.nodeLayer = nodeLayer
        
        let linkLayer = SKNode()
        drawLayer.addChild(linkLayer)
        self.linkLayer = linkLayer
        
        let backgroundLayer = SKNode()
        drawLayer.addChild(backgroundLayer)
        self.backgroundLayer = backgroundLayer
    }
    /// addChild후 레이어에 추가 설정
    private static func setLayerInitialState() {
        uiLayer.zPosition = PList.ZPosition.uiLayer
    }
    /// drawLayer 초기 설정
    private static func initDrawLayer() {
//        initNodeLayer()
//        initLinkLayer()
        initBackgroundLayer()
    }
    // 물체
    private static func initObjectLayer() {
        DungeonController.initDungeonScene()
    }
    // 배경
    private static func initBackgroundLayer() {
        var xPosition: CGFloat = GameVariable.movableRange.xRange.lowerBound
        for _ in 0...Int(GameVariable.mapSize.width * 2) {
            var yPosition: CGFloat = GameVariable.movableRange.yRange.lowerBound
            
            for _ in 0...Int(GameVariable.mapSize.height - 1) {
                AddChild.toBackgroundNode(imageName: PList.Name.Image.underground, x: xPosition, y: yPosition)
                yPosition += PList.Size.display.height
            }
            
            AddChild.toBackgroundNode(imageName: PList.Name.Image.landscape, x: xPosition, y: yPosition)
            AddChild.toBackgroundNode(imageName: PList.Name.Image.surface,
                                      x: xPosition, y: yPosition - 20, zPosition: PList.ZPosition.surface)
            AddChild.toBackgroundNode(imageName: PList.Name.Image.sky,
                                      x: xPosition, y: yPosition + PList.Size.display.height)
            
            xPosition += PList.Size.display.width
        }
    }
    
    static var tempRoomNode: SKSpriteNode!
    static var tempJointNode: SKSpriteNode!
    static var tempJointNodeOfLink: SKSpriteNode!
    static var tempLinkNode: SKSpriteNode!
    
    static var isDrawingPreview: Bool =  false
    
    /// 필요에 맞는 tempNode를 초기 설정한다
    static func initTempNode(looking point: CGPoint) {
        isDrawingPreview = true
        if UIData.doBuildRoom {
            initTempRoomNode(looking: point)
        } else {
            initTempJointNode(looking: point)
        }
        
        if TouchProcessor.touchCondition == .touchedNode {
            initTempLinkNodeFromNode(looking: point)
        } else if TouchProcessor.touchCondition == .touchedLink {
            initTempLinkNodeFromLink(looking: point)
            initTempJointNodeOfLink()
        }
    }
    
    /// 임시 방노드를 만든다
    private static func initTempRoomNode(looking point: CGPoint) {
        tempRoomNode = SKSpriteNode(imageNamed: PList.Name.Image.room)
        tempRoomNode.position = point
        tempRoomNode.zPosition = PList.ZPosition.previewNode
        tempRoomNode.alpha = 0.5
        tempRoomNode.size = CGSize(width: PList.Size.roomSide, height: PList.Size.roomSide)
        backgroundLayer.addChild(tempRoomNode)
    }
    /// 임시 이음노드를 만든다
    private static func initTempJointNode(looking point: CGPoint) {
        tempJointNode = SKSpriteNode(imageNamed: PList.Name.Image.joint)
        tempJointNode.position = point
        tempJointNode.zPosition = PList.ZPosition.previewNode
        tempJointNode.alpha = 0.5
        tempJointNode.size = CGSize(width: PList.Size.linkWidth, height: PList.Size.linkWidth)
        backgroundLayer.addChild(tempJointNode)
    }
    /// 임시 링크노드를 노드로부터 만든다
    private  static func initTempLinkNodeFromNode(looking point: CGPoint) {
        tempLinkNode = SKSpriteNode(imageNamed: PList.Name.Image.way)
        
        setLinkNodeOutline(node: tempLinkNode, alphaPoint: TouchProcessor.touchingObject.position, omegaPoint: point)
        tempLinkNode.zPosition = PList.ZPosition.previewLink
        tempLinkNode.alpha = 0.5
        
        backgroundLayer.addChild(tempLinkNode)
    }
    /// 링크의 임시 이음노드를 만든다
    private static func initTempJointNodeOfLink() {
        tempJointNodeOfLink = SKSpriteNode(imageNamed: PList.Name.Image.joint)
        tempJointNodeOfLink.position = TouchProcessor.touchingLinkPoint
        tempJointNodeOfLink.zPosition = PList.ZPosition.previewNode
        tempJointNodeOfLink.alpha = 0.5
        tempJointNodeOfLink.size = CGSize(width: PList.Size.linkWidth, height: PList.Size.linkWidth)
        backgroundLayer.addChild(tempJointNodeOfLink)
    }
    /// 임시 링크노드를 링크로부터 만든다
    private static func initTempLinkNodeFromLink(looking point: CGPoint) {
        tempLinkNode = SKSpriteNode(imageNamed: PList.Name.Image.way)
        
        setLinkNodeOutline(node: tempLinkNode, alphaPoint: TouchProcessor.touchingLinkPoint, omegaPoint: point)
        tempLinkNode.zPosition = PList.ZPosition.previewLink
        tempLinkNode.alpha = 0.5
        
        backgroundLayer.addChild(tempLinkNode)
    }
    
    /// 순수한 링크노드의 위치 설정. zposition 설정 없음, alpha설정 없음, 자식 설정 없음
    static func setLinkNodeOutline(node: SKSpriteNode, alphaPoint: CGPoint, omegaPoint: CGPoint) {
        let xPosition = (alphaPoint.x + omegaPoint.x) / 2
        let yPosition = (alphaPoint.y + omegaPoint.y) / 2
        node.position = CGPoint(x: xPosition, y: yPosition)
        
        let dx = omegaPoint.x - alphaPoint.x
        let dy = omegaPoint.y - alphaPoint.y
        let nodeHeight = sqrt(pow(dx, 2) + pow(dy, 2))
        
        node.zRotation = (asin(dy / nodeHeight) - CGFloat.pi / 2) * (dx > 0 ? 1 : -1)
        node.size = CGSize(width: PList.Size.linkWidth, height: nodeHeight - PList.Size.linkSpare)
    }
    
    /// 포인트에 따라 노드 위치 설정
    static func drawPreview(tracking point: CGPoint) {
        if UIData.doBuildRoom {
            tempRoomNode.position = point
        } else {
            tempJointNode.position = point
        }
        
        if TouchProcessor.touchCondition == .touchedNode {
            setLinkNodeOutline(node: tempLinkNode, alphaPoint: TouchProcessor.touchingObject.position, omegaPoint: point)
        } else if TouchProcessor.touchCondition == .touchedLink {
            setLinkNodeOutline(node: tempLinkNode, alphaPoint: TouchProcessor.touchingLinkPoint, omegaPoint: point)
        }
    }
    
    /// 드로우를 종료하며 프리뷰 노드를 부모로부터 제거한다
    static func endDrawing() {
        isDrawingPreview = false
        if UIData.doBuildRoom {
            tempRoomNode.removeFromParent()
        } else {
            tempJointNode.removeFromParent()
        }
        
        tempLinkNode.removeFromParent()
        
        if TouchProcessor.touchCondition == .touchedLink {
            tempJointNodeOfLink.removeFromParent()
        }
    }
    
}
