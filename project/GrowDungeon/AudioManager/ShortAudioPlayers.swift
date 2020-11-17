//
//  ShortAudioPlayer.swift
//  GrowDungeon
//
//  Created by 박정훈 on 11/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import AVFoundation

class ShortAudioPlayers: NSObject {
    static var players: [String: PlayerInformation] = [:]
    
    // 정확히 설정된 존재하는 url만 추가할 수 있다
    func addAudioNameOf(_ name:String, url: URL) {
        let playerItem = AVPlayerItem(url: url)
        let player = AVPlayer(playerItem: playerItem)
        ShortAudioPlayers.players.updateValue(PlayerInformation(player: player), forKey: name)
        playerItem.addObserver(self,
                               forKeyPath: #keyPath(AVPlayerItem.status),
                               options: [.old, .new],
                               context: &ShortAudioPlayers.players[name]!.playerItemContext)
    }
    
    // 재생
    func playAudioNameOf(_ name: String) {
        guard let playerInformation = ShortAudioPlayers.players[name] else {
            print("no short audio of that name")
            return
        }
        
        if playerInformation.isPlayerReadyToPlay, let playerItem = playerInformation.player.currentItem {
            let player = playerInformation.player
            playerItem.seek(to: CMTime.zero, completionHandler: nil)
            player.play()
        } else {
            print("didn't ready to play")
            print(playerInformation.isPlayerReadyToPlay)
        }
    }
    
    // 재생 가능한가 옵저브
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        
        print("observing")
        
        var informationBefore: PlayerInformation? = nil
        
        for (_, value) in ShortAudioPlayers.players {
            if &value.playerItemContext == context {
                informationBefore = value
            }
        }
        
        guard let information = informationBefore else {
            super.observeValue(forKeyPath: keyPath,
                               of: object,
                               change: change,
                               context: context)
            print("no context matches")
            return
        }
        
        if keyPath == #keyPath(AVPlayerItem.status) {
            let status: AVPlayerItem.Status
            // Get the status change from the change dictionary
            if let statusNumber = change?[.newKey] as? NSNumber {
                status = AVPlayerItem.Status(rawValue: statusNumber.intValue)!
            } else {
                status = .unknown
            }
            
            // Switch over the status
            switch status {
            case .readyToPlay:
                // Player item is ready to play.
                information.isPlayerReadyToPlay = true
            case .failed:
                // Player item failed. See error.
                print("failed status")
            case .unknown:
                // Player item is not yet ready.
                print("unknown status")
            }
        }
    }
    
}

// 플레이어 정보 클래스
class PlayerInformation {
    var player: AVPlayer
    var isPlayerReadyToPlay: Bool
    var playerItemContext: Int
    
    init(player: AVPlayer,
         isplayerReadyToPlay: Bool = false,
         context playerItemContext: Int = 0) {
        self.player = player
        self.isPlayerReadyToPlay = isplayerReadyToPlay
        self.playerItemContext = playerItemContext
    }
    
    func gotReadyToPlay() {
        isPlayerReadyToPlay = true
    }
}
