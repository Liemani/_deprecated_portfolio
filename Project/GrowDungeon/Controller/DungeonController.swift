//
//  DungeonController.swift
//  GrowDungeon
//
//  Created by 박정훈 on 13/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import UIKit
import SpriteKit

struct DungeonController {
    
    static var nodeDictionary: [SKSpriteNode: LMDungeon.LMNode] = [:]
    static var linkDictionary: [SKSpriteNode: LMDungeon.LMLink] = [:]
    
    private static func addChildToNodeLayer(lmNode: LMDungeon.LMNode) {
        var spriteNode: SKSpriteNode!
        SceneView.nodeLayer.addChildSpriteNode(from: lmNode) { (completeNode) in
            spriteNode = completeNode
        }
        nodeDictionary.updateValue(lmNode, forKey: spriteNode)
    }
    private static func addChildToLinkLayer(lmLink: LMDungeon.LMLink) {
        var spriteNode: SKSpriteNode!
        SceneView.nodeLayer.addChildSpriteNode(from: lmLink) { (completeNode) in
            spriteNode = completeNode
        }
        linkDictionary.updateValue(lmLink, forKey: spriteNode)
    }
    
    static func initDungeonScene() {
        LMDungeon.initDungeon()
        
        /*test code*/
        let xPosition = LMDungeon.nodeS[1].location.x - 400
        let yPosition = LMDungeon.nodeS[1].location.y - 400
         LMDungeon.addNode(from: LMDungeon.nodeS[1], to: CGPoint(x: xPosition, y: yPosition))
        /*test code*/
        
        for node in LMDungeon.nodeS {
            SceneView.nodeLayer.addChildSpriteNode(from: node)
        }
        for link in LMDungeon.linkS {
            SceneView.linkLayer.addChildSpriteNode(from: link)
        }
    }
    
    /// 룸노드나 조인트노드로부터 새로운 노드 생성
    static func addLMNodeFrom(touchLocation: CGPoint) {
        if let alphaNode = nodeDictionary[TouchProcessor.touchingObject] {
            LMDungeon.addNode(from: alphaNode, to: touchLocation, use: (UIData.doBuildRoom ? .room : .joint))
            SceneView.nodeLayer.addChildSpriteNode(from: LMDungeon.nodeS.last!)
            SceneView.linkLayer.addChildSpriteNode(from: LMDungeon.linkS.last!)
        }
    }
    /// 링크노드에서 새로운 노드 생성 tip: 가독성을 키우기 위해 코드 자체를 문서 읽듯이 읽을 수 있게 하자 -> 함수 이름을 더욱 가독성 있게 설정 및 다양한 기법 사용
    static func addLMNodeFromLink(to location: CGPoint) {
        if let touchedLinkNode = TouchProcessor.touchingObject,
            let lmLink = linkDictionary[touchedLinkNode] {
            // 1단계 : 링크 내에 노드를 만든다
            LMDungeon.addNode(from: lmLink, at: TouchProcessor.touchingLinkPoint, use: .joint)
            // 기존 linkSpriteNode 를 옮기고 새로운 linkSpriteNode 와 nodeSpriteNode 를 그린다
            touchedLinkNode.setLinkNodeOutline(from: lmLink.alphaNode.location, to: lmLink.omegaNode.location)
            SceneView.linkLayer.addChildSpriteNode(from: LMDungeon.linkS.last!)
            SceneView.nodeLayer.addChildSpriteNode(from: LMDungeon.nodeS.last!)
            // 2단계 : 만든 노드에서 주어진 위치로 새로운 노드와 링크를 만든다
            TouchProcessor.touchingObject = SceneView.nodeLayer.children.last as? SKSpriteNode // 트릭 코드
            addLMNodeFrom(touchLocation: location)
        }
    }
    
}
