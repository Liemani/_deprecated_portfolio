//
//  DrawSpriteNode.swift
//  GrowDungeon
//
//  Created by 박정훈 on 16/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

extension SKNode {
    /// imageName과 boundary로 spriteNode를 만들어 자식노드로 추가한다
    func addChildSpriteNode(imageName: String, boundary: CGRect) {
        let spriteNode: SKSpriteNode = SKSpriteNode(imageNamed: imageName)
        spriteNode.size = boundary.size
        
        spriteNode.position = boundary.origin
        
        addChild(spriteNode)
    }
    /// LMNode로부터 spriteNode를 만들어 자식노드로 추가한다
    func addChildSpriteNode(from lmNode: LMDungeon.LMNode, completion: (SKSpriteNode) -> Void = {_ in }) {
        let imageName: String
        let size: CGSize
        let zPosition: CGFloat
        
        switch lmNode.use {
        case .room:
            imageName = PList.Name.Image.room
            size = PList.Size.room
            zPosition = PList.ZPosition.room
        case .joint:
            imageName = PList.Name.Image.joint
            size = PList.Size.joint
            zPosition = PList.ZPosition.joint
        case .entrance:
            imageName = PList.Name.Image.entrance_cave
            size = PList.Size.entrance
            zPosition = PList.ZPosition.entrance
        }
        
        let spriteNode: SKSpriteNode = SKSpriteNode(imageNamed: imageName)
        spriteNode.size = size
        
        spriteNode.position = lmNode.location
        spriteNode.zPosition = zPosition
        
        addChild(spriteNode)
        
        completion(spriteNode)
    }
    /// LMLink로부터 spriteNode를 만들어 자식노드로 추가한다
    func addChildSpriteNode(from lmNode: LMDungeon.LMLink, completion: (SKSpriteNode) -> Void = {_ in }) {
        let spriteNode: SKSpriteNode = SKSpriteNode(imageNamed: PList.Name.Image.way)
        
        spriteNode.setLinkNodeOutline(from: lmNode.alphaNode.location, to: lmNode.omegaNode.location)
        spriteNode.zPosition = PList.ZPosition.link
        
        addChild(spriteNode)
        
        completion(spriteNode)
    }
    /// MapTile과 위치에 따라 배경노드를 만들어 자식노드로 추가한다
    func addChildBackgroundNode(mapTile: GameVariable.MapTile, at location: CGPoint) {
        let imageName: String
        
        switch mapTile {
        case .sky:
            imageName = PList.Name.Image.sky
        case .landscape:
            imageName = PList.Name.Image.landscape
        case .underground:
            imageName = PList.Name.Image.underground
        }
        
        let spriteNode: SKSpriteNode = SKSpriteNode(imageNamed: imageName)
        spriteNode.size = PList.Size.background
        
        spriteNode.position = location
        
        addChild(spriteNode)
    }
}

extension SKSpriteNode {
    func setPosition(to location: CGPoint) {
        position = location
    }
    /// set size, position, zRotation by alphaLocation and omegaLocation
    func setLinkNodeOutline(from alphaLocation: CGPoint, to omegaLocation: CGPoint) {
        let vector: CGPoint = omegaLocation - alphaLocation
        let nodeHeight = sqrt(pow(vector.x, 2) + pow(vector.y, 2))
        
        size = CGSize(width: PList.Size.linkWidth, height: nodeHeight - PList.Size.linkSpare)
        
        position = (alphaLocation + omegaLocation) / 2
        zRotation = (asin(vector.y / nodeHeight) - CGFloat.pi / 2) * (vector.x > 0 ? 1 : -1)
    }
}
