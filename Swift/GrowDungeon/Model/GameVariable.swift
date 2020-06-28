//
//  GameVariable.swift
//  GrowDungeon
//
//  Created by 박정훈 on 15/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//

import UIKit

struct GameVariable {
    
    enum MapTile {
        case sky
        case landscape
        case underground
    }
    
    /// width : 맵 사이즈는 양 옆으로 각각 몇 칸을 붙이는가, height : 지하로 몇 칸을 파는가
    static var mapExpansionSize: CGSize!
    static var mapSize: CGSize!
    static var movableRange: LCGRange2!
    static var movableRangeWithoutRestriction: LCGRange2!
    static var mapTileS: [[MapTile]]!
    /// init mapSize
    /// and set movableRange, movableRangeWithoutRestriction
    static func initMapExpansionSize(size: CGSize) {
        mapExpansionSize = size
        mapSize = CGSize(width: mapExpansionSize.width * 2 + 1, height: mapExpansionSize.height + 2)
        
        setMovableRange()
        setMovableRangeWithoutRestriction()
        mapTileSGenerator()
    }
    /// set movableRange
    private static func setMovableRange() {
        let movableXRange = ClosedRange<CGFloat>.init(uncheckedBounds: (lower: -PList.Size.display.width * mapExpansionSize.width,
                                                                        upper: PList.Size.display.width * mapExpansionSize.width))
        let movableYRange = ClosedRange<CGFloat>.init(uncheckedBounds: (lower: -PList.Size.display.height * mapExpansionSize.height,
                                                                        upper: PList.Size.display.height))
        movableRange = LCGRange2(xRange: movableXRange, yRange: movableYRange)
    }
    /// set movableRangeWithoutRestriction
    private static func setMovableRangeWithoutRestriction() {
        let xLowerBound = movableRange.xRange.lowerBound + PList.Size.display.width * 1 / PList.Size.restriction.width
        let xUpperBound = movableRange.xRange.upperBound - PList.Size.display.width * 1 / PList.Size.restriction.width
        let yLowerBound = movableRange.yRange.lowerBound + PList.Size.display.height * 1 / PList.Size.restriction.height
        let yUpperBound = movableRange.yRange.upperBound - PList.Size.display.height * 1 / PList.Size.restriction.height
        let movableXRangeWithoutRestriction = ClosedRange<CGFloat>.init(uncheckedBounds: (lower: xLowerBound,
                                                                                          upper: xUpperBound))
        let movableYRangeWithoutRestriction = ClosedRange<CGFloat>.init(uncheckedBounds: (lower: yLowerBound,
                                                                                          upper: yUpperBound))
        movableRangeWithoutRestriction = LCGRange2(xRange: movableXRangeWithoutRestriction,
                                                   yRange: movableYRangeWithoutRestriction)
    }
    /// generate mapTiles
    private static func mapTileSGenerator() {
        var rowMapTileS: [MapTile] = []
        for _ in 0...Int(mapSize.width - 1) {
            rowMapTileS.append(.sky)
        }
        mapTileS.append(rowMapTileS)
        
        rowMapTileS = []
        for _ in 0...Int(mapSize.width - 1) {
            rowMapTileS.append(.landscape)
        }
        mapTileS.append(rowMapTileS)
        
        for _ in 0...Int(mapExpansionSize.height - 1) {
            rowMapTileS = []
            for _ in 0...Int(mapSize.width - 1) {
                rowMapTileS.append(.underground)
            }
            mapTileS.append(rowMapTileS)
        }
    }
    
}
