//
//  main.swift
//  unionFind
//
//  Created by KiUng Jung on 2017. 12. 12..
//  Copyright © 2017 KiUng Jung. All rights reserved.
//

import UIKit


struct UnionFind {
    var setCount:Int
    var largestSize:Int
    var count:Int
    var parent = [Int]()
    var rank = [Int]()
    var size = [Int]()
    
    
    init?(size:Int) {
        if(size < 0) {
            return nil
        }
        self.setCount = size
        self.largestSize = 1
        self.count = size
        self.parent = Array(0..<size)
        self.rank = Array(repeatElement(1, count: size))
        self.size = Array(repeatElement(1, count: size))
    }

    mutating func find(parentOf me:Int) -> Int? {
        if me < 0 || count <= me {
            return nil
        }
        if me == self.parent[me] {
            return me
        }
        self.parent[me] = find(parentOf: parent[me])
        return self.parent[me]
    }
    
    @discardableResult mutating func merge(setOf a:Int, setOf b:Int) -> Bool? {
        if a < 0 || count <= a || b < 0 || count <= b {
            return nil
        }
        
        var a = find(parentOf: a)
        var b = find(parentOf: b)
        
        if a == b {
            return false
        }
        
        if self.size[a] < self.size[b] {
            swap(&a, &b)
        }
        self.parent[b] = a
        if self.rank[a] == self.rank[b] {
            self.rank[a] += 1
        }
        
        self.setCount -= 1
        self.size[a] += self.size[b]
        self.largestSize = max(self.largestSize, self.size[a])
        
        return true
    }
}








