//
//  UIController.swift
//  GrowDungeon
//
//  Created by 박정훈 on 16/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import SpriteKit

struct UIController {
    
    static var isEditMode: Bool = PList.Bool.isEditMode
    static var isMakeRoomMode: Bool = PList.Bool.isMakeRoomMode
    
    static func initUILayer() {
        SceneView.uiLayer.addChildSpriteNode(imageName: PList.Name.Image.button_observe,
                                             boundary: CGRect(x: -290, y: -140, width: 70, height: 70))
        SceneView.uiLayer.addChildSpriteNode(imageName: PList.Name.Image.isRoom_true,
                                             boundary: CGRect(x: -220, y: -150, width: 50, height: 50))
    }
    static func turnIsEditMode() {
        isEditMode = !isEditMode
        
        let editButton = SceneView.uiLayer.children[0] as! SKSpriteNode
        if isEditMode {
            if let image = UIImage(named: PList.Name.Image.button_edit) {
                editButton.texture = SKTexture(image: image)
            }
        } else {
            if let image = UIImage(named: PList.Name.Image.button_observe) {
                editButton.texture = SKTexture(image: image)
            }
        }
    }
    static func turnIsMakeRoomMode() {
        isMakeRoomMode = !isMakeRoomMode
        
        let editButton = SceneView.uiLayer.children[1] as! SKSpriteNode
        if isMakeRoomMode {
            if let image = UIImage(named: PList.Name.Image.isRoom_true) {
                editButton.texture = SKTexture(image: image)
            }
        } else {
            if let image = UIImage(named: PList.Name.Image.isRoom_false) {
                editButton.texture = SKTexture(image: image)
            }
        }
    }
    
}
