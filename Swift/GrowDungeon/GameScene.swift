//
//  GameScene.swift
//  GrowDungeon
//
//  Created by 박정훈 on 07/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

class GameScene: SKScene{
    
    override func didMove(to view: SKView) {
        initialSetting()
    }
    
    func initialSetting() {
        initGameData()
        initCamera()
        SceneView.initScene(rootNode: self)
        AudioManager.playLongAudio(name: PList.Name.Key.bgm)
    }
    /// 각종 게임 데이터 초기 설정
    func initGameData() {
        GameVariable.initMapExpansionSize(size: CGSize(width: 2, height: 3))
    }
    /// 카메라 관련 초기 설정
    func initCamera() {
        let camera = SKCameraNode()
        addChild(camera)
        self.camera = camera
        TouchProcessor.camera = camera
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touchPoint = touches.first?.location(in: self) else { return }

        TouchProcessor.toucheBegan(touchPoint)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touchPoint = touches.first?.location(in: self) else { return }
        
        TouchProcessor.touchMoved(point: touchPoint)
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        TouchProcessor.touchEnded()
    }
    
    override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
        TouchProcessor.touchEnded()
    }
    
    override func update(_ currentTime: TimeInterval) {
        if TouchProcessor.isAnimating {
            if CameraController.isAnimating {
                CameraController.moveCameraIntoMovableRangeWithoutRestriction()
            } else {
                CameraController.initToAnimate()
            }
        }
    }
    
}
