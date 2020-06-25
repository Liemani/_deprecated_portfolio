//
//  GameViewController.swift
//  PropagationDefense
//
//  Created by 박정훈 on 2018. 10. 18..
//  Copyright © 2018년 LIARS. All rights reserved.
//

import UIKit
import SpriteKit

class GameViewController: UIViewController {
    
    var skView: SKView!
    var scene: SKScene!

    override func viewDidLoad() {
        super.viewDidLoad()
        setViewAndScene()
    }
    
    func setViewAndScene() {
        skView = view as? SKView
        CustomPrint.judgeMessage(skView, description: "skView", "casting")
        
        scene = GameScene()
        scene.size = CGSize(width: 667, height: 375)
        CustomPrint.judgeMessage(scene, description: "scene", "init")
        scene.scaleMode = .aspectFill
        
        skView.presentScene(scene)
        skView.ignoresSiblingOrder = true
        skView.showsFPS = true
        skView.showsNodeCount = true
    }
    
    override var shouldAutorotate: Bool { return true }

    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        return UIDevice.current.userInterfaceIdiom == .phone ? .allButUpsideDown : .all
    }

    override var prefersStatusBarHidden: Bool { return true }
}
