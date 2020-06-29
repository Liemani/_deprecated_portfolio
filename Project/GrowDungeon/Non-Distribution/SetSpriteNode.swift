//
//  SetSpriteNode.swift
//  GrowDungeon
//
//  Created by 박정훈 on 15/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

struct SetSpriteNode {
    static func setLinkNode(_ linkNode: SKSpriteNode, alphaPoint: CGPoint, omegaPoint: CGPoint) {
        let xPosition = (alphaPoint.x + omegaPoint.x) / 2
        let yPosition = (alphaPoint.y + omegaPoint.y) / 2
        linkNode.position = CGPoint(x: xPosition, y: yPosition)
        
        let dx = omegaPoint.x - alphaPoint.x
        let dy = omegaPoint.y - alphaPoint.y
        let nodeHeight = sqrt(pow(dx, 2) + pow(dy, 2))
        
        linkNode.zRotation = (asin(dy / nodeHeight) - CGFloat.pi / 2) * (dx > 0 ? 1 : -1)
        linkNode.size = CGSize(width: PList.Size.linkWidth, height: nodeHeight - PList.Size.linkSpare)
    }
}
