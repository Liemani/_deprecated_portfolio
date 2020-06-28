//
//  AudioManager.swift
//  GrowDungeon
//
//  Created by 박정훈 on 11/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import Foundation

class AudioManager {
    
    private static let longAudioPlayers: LongAudioPlayers = LongAudioPlayers()
    private static let shortAudioPlayers: ShortAudioPlayers = ShortAudioPlayers()
    
    static func addShortAudio(name: String, url: URL) {
        shortAudioPlayers.addAudioNameOf(name, url: url)
    }
    
    static func addLongAudio(name: String, url: URL) {
        longAudioPlayers.addAudioNameOf(name, url: url)
    }
    
    static func playShortAudio(name: String) {
        shortAudioPlayers.playAudioNameOf(name)
    }
    
    static func playLongAudio(name: String) {
        longAudioPlayers.playAudioInfinitelyNameOf(name)
    }
    
}
