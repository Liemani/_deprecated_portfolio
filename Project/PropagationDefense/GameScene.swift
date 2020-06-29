//
//  GameScene.swift
//  PropagationDefense
//
//  Created by 박정훈 on 2018. 10. 22..
//  Copyright © 2018년 LIARS. All rights reserved.
//
//  할일
//
//  식량을 만들고
//  식량을 확보하는 버튼을 만들고 - 골드 소모
//  인구에 비례하게 식량이 줄어들고
//  스테이스메세지를 중앙에 표시
//  여행이 확률적으로 실패하도록 혹은 10명이 가서 1명이 늘도록 확률적으로 위인을 데려옴
//  생성되는 여행객을 다변적으로 만들기
//
//  상태 메세지에 다양한 설명 추가, 배경색을 반투명 흰 색으로 설정
//  어플 그림 넣기
//


import SpriteKit
import AVFoundation
import AVKit

class GameScene: SKScene {
    
    let windowWidth: Int = 667
    let windowHeight: Int = 375
    
    let backgroundLayerZPosition: CGFloat = -100
    let uiLayerZPosition: CGFloat = 100
    
    let gameTime: GameTime = GameTime()
    
    var population: Double = 10
    var gold: Double = 10
    var food: Double = 10
    
    var travelingPerson: SKSpriteNode!
    
    var isTouchingTravel: Bool = false
    
    let soundManager: SoundManager = SoundManager()
    
    // MARK: - initializing
    override func didMove(to view: SKView) {
        soundManager.playInfiniteRepeat()
        
        setScene()
    }
    
    func setScene() {
        
        setBackgroundLayer()
        setUILayer()
        setActionLayer()
    }
    
    func setBackgroundLayer() {
        let backgroundLayer = SKNode()
        backgroundLayer.zPosition = backgroundLayerZPosition
        addChild(backgroundLayer)
        
        addNodeTo(layer: backgroundLayer, imageName: "background", x: 0, y: 0, width: windowWidth, height: windowHeight, zPosition: -2)
        addNodeTo(layer: backgroundLayer, imageName: "ground", x: 0, y: 0, width: windowWidth, height: 70)
        addNodeTo(layer: backgroundLayer, imageName: "grass", x: 0, y: 70, width: windowWidth, height: 5)
        addNodeTo(layer: backgroundLayer, imageName: "castle", x: 100, y: 75, width: 50, height: 100)
        addNodeTo(layer: backgroundLayer, imageName: "cloud", x: -100, y: 280, width: 100, height: 40)
        backgroundLayer.children[4].run(SKAction.repeatForever(SKAction.sequence([SKAction.moveTo(x: 667, duration: 256),
                                                                                  SKAction.moveTo(x: -100, duration: 0)])))
        addNodeTo(layer: backgroundLayer, imageName: "person", x: 40, y: 75, width: 20, height: 40)
        addNodeTo(layer: backgroundLayer, imageName: "sun", x: 617, y: 325, width: 50, height: 50, zPosition: -1)
    }
    
    func setUILayer() {
        let uiLayer = SKNode()
        uiLayer.zPosition = uiLayerZPosition
        addChild(uiLayer)
        
        setUILabelLayer()
        
        addNodeTo(layer: uiLayer, imageName: "person", x: 5, y: 340, width: 30, height: 30)
        addNodeTo(layer: uiLayer, imageName: "gold", x: 195, y: 340, width: 30, height: 30)
        addNodeTo(layer: uiLayer, imageName: "food", x: 385, y: 340, width: 30, height: 30)
        addNodeTo(layer: uiLayer, imageName: "button", x: 5, y: 5, width: 60, height: 60)
//        addNodeTo(layer: uiLayer, imageName: "button", x: 75, y: 5, width: 60, height: 60)
//        addNodeTo(layer: uiLayer, imageName: "button", x: 145, y: 5, width: 60, height: 60)
//        addNodeTo(layer: uiLayer, imageName: "button", x: 215, y: 5, width: 60, height: 60)
//        addNodeTo(layer: uiLayer, imageName: "button", x: 285, y: 5, width: 60, height: 60)
    }
    
    func setUILabelLayer() {
        let uiLabelLayer = SKNode()
        uiLabelLayer.zPosition = uiLayerZPosition
        children[1].addChild(uiLabelLayer)
        
        addLabelNodeTo(layer: uiLabelLayer, text: "인구", x: 45, y: 345)
        addLabelNodeTo(layer: uiLabelLayer, text: "골드", x: 235, y: 345)
        addLabelNodeTo(layer: uiLabelLayer, text: "식량", x: 425, y: 345)
        addLabelNodeTo(layer: uiLabelLayer, text: "여행", x: 15, y: 25)
        addLabelNodeTo(layer: uiLabelLayer, text: "", x: 75, y: 25, color: .white)  // 상태 메세지
    }
    
    func setActionLayer() {
        let actionLayer = SKNode()
        addChild(actionLayer)
        
        travelingPerson = SKSpriteNode(imageNamed: "person")
        CustomPrint.judgeMessage(travelingPerson, description: "travelingPerson", "init")
        travelingPerson.anchorPoint = CGPoint(x: 0, y: 0)
        travelingPerson.position = CGPoint(x: 190, y: 75)
        travelingPerson.size = CGSize(width: 20, height: 40)
        
        addNodeTo(layer: actionLayer, imageName: "person", x: 170, y: 75, width: 20, height: 40)
        actionLayer.children[0].isHidden = true
    }

    func addNodeTo(layer: SKNode, imageName: String, x: Int, y: Int, width: Int, height: Int, zPosition: CGFloat = 0) {
        let node = SKSpriteNode(imageNamed: imageName)
        node.anchorPoint = CGPoint(x: 0, y: 0)
        node.position = CGPoint(x: x, y: y)
        node.size = CGSize(width: width, height: height)
        node.zPosition = zPosition
        layer.addChild(node)
    }
    
    func addLabelNodeTo(layer: SKNode, text: String, x: Int, y: Int, color: UIColor = .black, zPosition: CGFloat = 1) {
        let node = SKLabelNode(text: text)
        node.position = CGPoint(x: x, y: y)
        node.zPosition = zPosition
        node.fontColor = color
        node.horizontalAlignmentMode = .left
        node.fontSize = 20
        layer.addChild(node)
    }
    
    // MARK: - game logic
    override func update(_ currentTime: TimeInterval) {
        guard gameTime.shouldSetTime == false else {
            gameTime.previousTime = currentTime
            gameTime.shouldSetTime = false
            return
        }
        let timeInteerval = currentTime - gameTime.previousTime
        
        // population label
        let populationIncrement = population / 6000
        population += populationIncrement * timeInteerval
        if let populationLabelNode = children[1].children[0].children[0] as? SKLabelNode {
            populationLabelNode.text = "\(Int(population)) (\((populationIncrement * 10).rounded() / 10) 명/s)"
        }
        
        // gold label
        let goldIncrement = population / 60
        gold += goldIncrement * timeInteerval
        if let goldLabelNode = children[1].children[0].children[1] as? SKLabelNode {
            goldLabelNode.text = "\(Int(gold)) (\((goldIncrement * 10).rounded() / 10) 골드/s)"
        }
        
        // meat label
        let foodIncrement =  population / 60
        gold += goldIncrement * timeInteerval
        if let goldLabelNode = children[1].children[0].children[1] as? SKLabelNode {
            goldLabelNode.text = "\(Int(gold)) (\((goldIncrement * 10).rounded() / 10) 골드/s)"
        }
        
        gameTime.previousTime = currentTime
    }
    
    // MARK: - touch event
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touchedLocation = touches.first?.location(in: self) else { return }
        
        if children[1].children[3].contains(touchedLocation) {
            isTouchingTravel = true
            printStateLabel(message: "마을원 10명을 여행보냅니다. 무사히 귀환하면 인구 +1 (소요 시간 20초)")
        } else {
            printStateLabel(message: "")
        }
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touchedLocation = touches.first?.location(in: self) else { return }
        if isTouchingTravel {
            if children[1].children[3].contains(touchedLocation) {
                printStateLabel(message: "마을원 10명을 여행보냅니다. 무사히 귀환하면 인구 +1 (소요 시간 20초)")
            } else {
                printStateLabel(message: "")
            }
        }
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touchedLocation = touches.first?.location(in: self) else { return }
        
        if children[1].children[3].contains(touchedLocation) && isTouchingTravel {
            makePersonTravel()
            isTouchingTravel = false
        } else {
            isTouchingTravel = false
        }
    }
    
    // MARK: - etc functions
    func makePersonTravel() {
        if population >= 10 {
            guard let travelingPerson = travelingPerson.copy() as? SKSpriteNode else { return }
            
            addChild(travelingPerson)
            
            travelingPerson.run(SKAction.sequence([SKAction.move(to: CGPoint(x: 700, y: 75), duration: 8),
                                                   SKAction.wait(forDuration: 4),
                                                   SKAction.move(to: CGPoint(x: 170, y: 75), duration: 8),
                                                   SKAction.removeFromParent()])) {
                                                    self.printStateLabel(message: "여행을 떠났던 사람들이 무사히 돌아왔어요")
                                                    self.population += 11
            }
            population -= 10
            printStateLabel(message: "")
        } else {
            printStateLabel(message: "여행보낼 사람이 부족해요")
        }
    }
    
    func printStateLabel(message: String) {
        if let stateLabel = children[1].children[0].children[3] as? SKLabelNode {
            stateLabel.text = String(message)
        }
    }
}
