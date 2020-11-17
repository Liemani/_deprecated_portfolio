//
//  Helper.swift
//  GrowDungeon
//
//  Created by 박정훈 on 15/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

extension CGPoint {
    static prefix func - (point: CGPoint) -> CGPoint {
        return CGPoint(x: -point.x, y: -point.y)
    }
    static func + (lhs: CGPoint, rhs: CGPoint) -> CGPoint {
        return CGPoint(x: lhs.x + rhs.x, y: lhs.y + rhs.y)
    }
    static func - (lhs: CGPoint, rhs: CGPoint) -> CGPoint {
        return CGPoint(x: lhs.x - rhs.x, y: lhs.y - rhs.y)
    }
    static func / (lhs: CGPoint, rhs: CGFloat) -> CGPoint {
        return CGPoint(x: lhs.x / rhs, y: lhs.y / rhs)
    }
}
