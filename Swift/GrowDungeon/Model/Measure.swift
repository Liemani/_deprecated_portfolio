//
//  Measure.swift
//  GrowDungeon
//
//  Created by 박정훈 on 14/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import UIKit

/// 두 개의 범위를 변수로 갖는 데이터 타입
struct LCGRange2 {
    
    var xRange: ClosedRange<CGFloat>
    var yRange: ClosedRange<CGFloat>
    /// 포인트가 범위 안에 있는가
    /// instance 변수가 주어이고 메서드 이름이 동사이다, 메서드 이름을 명제로 만들어서 참과 거짓을 판별할 수 있는 문장이 되었다
    func contains(_ point: CGPoint) -> Bool {
        if xRange.contains(point.x) && yRange.contains(point.y) {
            return true
        } else {
            return false
        }
    }
    
}
