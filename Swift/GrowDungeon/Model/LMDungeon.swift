//
//  Dungeon.swift
//  GrowDungeon
//
//  Created by 박정훈 on 08/11/2018.
//  Copyright © 2018 LIARS. All rights reserved.
//
// 이후 노드와 링크에 다양한 특성 추가
// 나중에 퓨어한 노드 연결 모델 데이터 타입을 만들어서 재사용 가능하도록 하자

import UIKit

struct LMDungeon {
    // remove(link:)와 removeLink(from:)은 서로 다른 메서드인데 전자가 더 세세한 조작을 할 때 붙이기 좋은 이름이고
    // 후자가 더 추상적인 조작을 할 때 붙이기 좋은 이름이다
    
    /// 명목상 오브젝트
    class LMObject {
    }
    /// LMNode - 노드, (let 위치, var 링크들, 룸인가), (초기 설정), (주어진 링크 추가, 노드로 링크 추가, 주어진 링크를 배열에서 제거)
    class LMNode: LMObject {
        enum Use {
            case entrance
            case room
            case joint
        }
        
        let location: CGPoint
        
        var linkS: [LMLink]
        var use: Use
        
        init(position: CGPoint, linkS: [LMLink] = [], use: Use = .room) {
            self.location = position
            self.linkS = linkS
            self.use = use
        }
        
        /// 링크로 링크 추가
        func addLink(from link: LMLink) {
            linkS += [link]
        }
        
        /// 두 노드로 링크 추가
        func addLink(alphaNode: LMNode, omegaNode: LMNode) {
            let link = LMLink(from: alphaNode, to: omegaNode)
            linkS += [link]
        }
        
        /// 링크 배열에서 해당 링크 제거
        func remove(link: LMLink) {
            var index: Int = 0
            for element in linkS {
                if element === link {
                    linkS.remove(at: index)
                } else {
                }
                index += 1
            }
        }
        
    }
    /// LMLink - 노드간의 연결, (let 알파노드, var 오메가노드), (초기 설정), (오메가 교체)
    class LMLink: LMObject {
        /// 알파 노드
        let alphaNode: LMNode
        /// 오메가 노드
        var omegaNode: LMNode
        
        init(from alphaNode: LMNode, to omegaNode: LMNode) {
            self.alphaNode = alphaNode
            self.omegaNode = omegaNode
        }
        /// 오메가노드 교체
        func replaceOmegaNode(node: LMNode) {
            omegaNode = node
        }
        
    }
    
    /// 노드 프로퍼티
    static var nodeS: [LMNode] = []
    /// 링크 프로퍼티
    static var linkS: [LMLink] = []
    
    /// 노드 추가 제거
    private static func add(node: LMNode) {
        nodeS.append(node)
    }
    private static func remove(node: LMNode) {
        var index: Int = 0
        for element in nodeS {
            if element === node {
                nodeS.remove(at: index)
            }
            index += 1
        }
    }
    
    /// 링크 추가 제거
    private static func add(link: LMLink) {
        linkS.append(link)
    }
    private static func remove(link: LMLink) {
        var index: Int = 0
        for element in linkS {
            if element === link {
                linkS.remove(at: index)
            }
            index += 1
        }
    }
    
    /// 조인트인지 확인하여 링크가 비어있으면 해당 노드를 제거한다
    private static func ifNoRoomAndHasEmptyLinkSThanRemoveNode(_ node: LMNode) {
        if node.use == .joint {
            if node.linkS.isEmpty {
                remove(node: node)
            }
        }
    }
    
    /// 던전 초기 설정
    static func initDungeon() {
        nodeS.removeAll()
        linkS.removeAll()
        // 입구
        addNode(to: CGPoint(x: PList.Size.display.width / 2, y: 50), use: .entrance)
        // 첫 방과 통로
        addNode(from: nodeS[0], to: CGPoint(x: PList.Size.display.width / 2, y: -165))
    }
    
    /// 주석 연습 주어진 위치에 노드를 추가
    ///
    /// 디스커션 엄슴
    ///
    ///     테스트 코드도 엄슴
    ///
    /// - Parameter nodePosition: 노드의 위치
    /// - Parameter isNodeRoom: 노드가 룸인가?
    /// - Returns: 만든 노드
    ///
    /// - Complexity: 머름
    @discardableResult  // 리턴 데이터를 사용하지 않아도 컴파일러가 에러 메세지를 띄우지 않도록 설정하는 명령어
    private static func addNode(to nodePosition: CGPoint, use: LMNode.Use = .room) -> LMNode {
        let node = LMNode(position: nodePosition, linkS: [], use: use)
        add(node: node)
        
        return node
    }
    /// add new (lmLink) at passed two (existing lmNode)
    static func addLinkToExistingNode(from alphaNode: LMNode, to omegaNode: LMNode) {
        let link = LMLink(from: alphaNode, to: omegaNode)
        add(link: link)
        
        omegaNode.addLink(from: link)
        alphaNode.addLink(from: link)
    }
    /// add new (lmLink) & (lmNode) from (existing lmNode) to passed location
    static func addNode(from alphaNode: LMNode, to omegaNodePosition: CGPoint, use: LMNode.Use = .room) {
        let omegaNode = addNode(to: omegaNodePosition, use: use)
        addLinkToExistingNode(from: alphaNode, to: omegaNode)
    }
    /// add new (lmNode) at passed location on (existing lmNode)
    static func addNode(from link: LMLink, at intermediateNodePosition: CGPoint, use: LMNode.Use = .room) {
        let intermediateNode = addNode(to: intermediateNodePosition, use: use)
        addLinkToExistingNode(from: intermediateNode, to: link.omegaNode)
        
        link.omegaNode.remove(link: link)
        link.replaceOmegaNode(node: intermediateNode)
    }
    /// remove (existing lmLink)
    static func removeLink(_ link: LMLink) {
        link.alphaNode.remove(link: link)
        ifNoRoomAndHasEmptyLinkSThanRemoveNode(link.alphaNode)
        
        link.omegaNode.remove(link: link)
        ifNoRoomAndHasEmptyLinkSThanRemoveNode(link.omegaNode)
        
        remove(link: link)
    }
    
    /// 방 설정 on
    static func turnOnRoom(node: LMNode) {
        node.use = .room
    }
    /// 방 설정 off
    static func turnOffRoom(node: LMNode) {
        node.use = .joint
    }
}
