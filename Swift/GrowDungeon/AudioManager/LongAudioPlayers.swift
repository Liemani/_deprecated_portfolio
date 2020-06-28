//
//  SoundManager.swift
//  
//
//  Created by 박정훈 on 11/11/2018.
//

import AVFoundation

class LongAudioPlayers: NSObject, AVAudioPlayerDelegate {
    static var players: [String: AVAudioPlayer] = [:]
    static var infinitePlayers: [AVAudioPlayer] = []
    
    func addAudioNameOf(_ name:String, url: URL) {
        guard let player = try? AVAudioPlayer(contentsOf: url) else { return }
        
        LongAudioPlayers.players.updateValue(player, forKey: name)
    }
    
    // name의 오디오를 처음부터 재생
    func playAudioNameOf(_ name: String) {
        guard let player = LongAudioPlayers.players[name] else {
            print("no audio of that name")
            return
        }
        
//        player.stop()
//        player.prepareToPlay()
//        print("stop and play")
        player.play()
    }
    
    // name의 오디오의 딜리게이트를 자신으로 설정하고 오디오를 재생
    func playAudioInfinitelyNameOf(_ name: String) {
        guard let player = LongAudioPlayers.players[name] else {
            print("no infinite audio of that name")
            return
        }
        
        player.play()
        player.delegate = self
    }
    
    // 딜리게이트가 설정된 오디오는 무한 재생
    func audioPlayerDidFinishPlaying(_ player: AVAudioPlayer, successfully flag: Bool) {
        player.play()
    }
}


