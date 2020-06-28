//
//  PropertyList.swift
//  GrowDungeon
//
//  Created by 박정훈 on 08/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import UIKit

struct PList {
    
    struct Name {
        struct Image {
            static let sky: String = "sky"
            static let landscape: String = "landscape"
            static let surface: String = "surface"
            static let underground: String = "underground"
            
            static let entrance_cave: String = "entrance_cave"
            static let entrance_arch: String = "entrance_arch"
            static let room: String = "room"
            static let joint: String = "joint"
            static let way: String = "way"
            
            static let button_observe: String = "button_observe"
            static let button_edit: String = "button_edit"
            
            static let isRoom_false: String = "isRoom_false"
            static let isRoom_true: String = "isRoom_true"
        }
        
        struct Key {
            static let bgm: String = "bgm"
            static let button: String = "button_tap_sound"
        }
    }
    
    struct ZPosition {
        static let lmNode: CGFloat = 1
        static let room: CGFloat = ZPosition.lmNode
        static let joint: CGFloat = ZPosition.lmNode
        static let lmNodeWall: CGFloat = 2
        
        static let link: CGFloat = 3
        static let linkWall: CGFloat = 4
        
        static let entrance: CGFloat = 5
        
        static let previewNode: CGFloat = 6
        static let previewNodeWall: CGFloat = 7
        
        static let previewLink: CGFloat = 8
        static let previewLinkWall: CGFloat = 9
        
        static let surface: CGFloat = 10
        static let uiLayer: CGFloat = 50
    }
    
    struct Size {
        static let display: CGSize = CGSize(width: 667, height: 375)
        static let background: CGSize = CGSize(width: Size.display.width + 1, height: Size.display.height + 1)
        
        static let restriction: CGSize = CGSize(width: 2.5, height: 2.5)
        
        static let joint: CGSize = CGSize(width: 50, height: 50)
        static let entrance: CGSize = CGSize(width: 100, height: 100)
        static let room: CGSize = CGSize(width: 150, height: 150)
        
        static let linkWidth: CGFloat = CGFloat(50)
        static let linkSpare: CGFloat = Size.room.width
    }
    
    struct Position {
        static let initCameraPosition: CGPoint = CGPoint(x: 0, y: -30)
    }
    
    struct Url {
        static let backgroundMusic: URL = Bundle.main.url(forResource: "background music", withExtension: "mp3")!
        static let buttonTapSound: URL = Bundle.main.url(forResource: "button sound", withExtension: "mp3")!
    }
    
    struct Duration {
        static let movingLayerFlip: Double = 0.3
    }
    
    struct Bool {
        static let isEditMode = false
        static let isMakeRoomMode = true
    }
    
}

