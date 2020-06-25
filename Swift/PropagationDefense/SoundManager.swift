//
//  Sound.swift
//  PropagationDefense
//
//  Created by 박정훈 on 2018. 10. 23..
//  Copyright © 2018년 LIARS. All rights reserved.
//

import AVKit

class SoundManager: NSObject {
    var backgroundMusicAsset: AVAsset
    var backgroundMusicItem: AVPlayerItem
    var player: AVPlayer
    var playerItemContext: Int = 0
    
    override init() {
        backgroundMusicAsset = AVAsset(url: MyURL.backgroundMusic)
        backgroundMusicItem = AVPlayerItem(asset: backgroundMusicAsset)
        player = AVPlayer(playerItem: backgroundMusicItem)
    }
    
    func playInfiniteRepeat() {
        backgroundMusicItem.addObserver(self,
                                        forKeyPath: #keyPath(AVPlayerItem.status),
                                        options: [.old, .new],
                                        context: &playerItemContext)
        addBoundaryTimeObserver()
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        // Only handle observations for the playerItemContext
        guard context == &playerItemContext else {
            super.observeValue(forKeyPath: keyPath,
                               of: object,
                               change: change,
                               context: context)
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
                player.play()
            case .failed:
                // Player item failed. See error.
                print("failed status")
            case .unknown:
                // Player item is not yet ready.
                print("unknown status")
            }
        }
    }
    
    func addBoundaryTimeObserver() {
        let times = [CMTimeMultiplyByFloat64(backgroundMusicAsset.duration, multiplier: 0.999)]
        player.addBoundaryTimeObserver(forTimes: times as [NSValue],
                                       queue: .main) {
                                        self.player.seek(to: CMTime(value: 0, timescale: 1))
                                        self.player.play()
        }
    }
}
