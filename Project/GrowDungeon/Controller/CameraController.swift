//
//  Animation.swift
//  
//
//  Created by 박정훈 on 08/11/2018.
//

import SpriteKit

struct CameraController {
    // 상태변수
    static var isAnimating: Bool = false
    // 시간 변수
    static var startTime: Double!
    static var duration: Double!
    // 위치 변수
    static var moveVector: CGVector!
    static var destinationPoint: CGPoint!
    
    /// 애니메이트하기 위한 기초 설정
    static func initToAnimate() {
        isAnimating = true
        
        startTime = Date.timeIntervalSinceReferenceDate
        self.duration = PList.Duration.movingLayerFlip
        
        let startPosition = TouchProcessor.camera.position
        destinationPoint = TouchProcessor.findNearestInnerPoint()
        moveVector = CGVector(dx: destinationPoint.x - startPosition.x,
                              dy: destinationPoint.y - startPosition.y)
    }
    /// 카메라를를 무버블랭지윋아웃레스트릭션 안쪽 목적지로 계산하여 위치를 설정합니다
    static func moveCameraIntoMovableRangeWithoutRestriction() {
        if Date().timeIntervalSinceReferenceDate < startTime + duration {
            let elapsedTime = Date().timeIntervalSinceReferenceDate - startTime
            
            let base = CGFloat(1 - elapsedTime / duration )
            let cube = pow(base, 3)
            let xPosition = destinationPoint.x - moveVector.dx * cube
            let yPosition = destinationPoint.y - moveVector.dy * cube
            TouchProcessor.camera.position = CGPoint(x: xPosition, y: yPosition)
        } else {
            TouchProcessor.camera.position = destinationPoint
            stopAnimating()
        }
    }
    // 애니메이팅 중지
    static func stopAnimating() {
        TouchProcessor.isAnimating = false
        isAnimating = false
    }
    
}
