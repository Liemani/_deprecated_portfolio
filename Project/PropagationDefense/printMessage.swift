//
//  printMessage.swift
//  PropagationDefense
//
//  Created by 박정훈 on 2018. 10. 22..
//  Copyright © 2018년 LIARS. All rights reserved.
//

import Foundation

class CustomPrint {
    
    static func judgeMessage(_ object: Any?, description: String, _ method: String) {
        if object == nil {
            failMessage(description, "init")
        } else {
            succeedMessage(description, "init")
        }
    }
    
    static func failMessage(_ object: String, _ method: String) {
        print("[\(object) \(method)] failed")
    }
    
    static func succeedMessage(_ object: String, _ method: String) {
        print("[\(object) \(method)] succeeded")
    }
    
}
