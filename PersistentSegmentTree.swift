//
//  main.swift
//  PST(Persistent Segment Tree)
//
//  Created by KiUng Jung on 2017. 11. 26..
//  Copyright © 2017 KiUng Jung. All rights reserved.
//

import Foundation

class Node {
    var value:Int = 0
    var left:Node!
    var right:Node!
}

func makeTree(node:Node, l:Int, r:Int, value:Int, idx:Int) -> Node {
    if idx < l || r < idx {return node}
    let new = Node()
    if l == r {
        new.value = value
        return new
    }
    new.left = makeTree(node: node.left, l: l, r: (l+r)/2, value: value, idx: idx)
    new.right = makeTree(node: node.right, l: (l+r)/2+1, r: r, value: value, idx: idx)
    new.value = new.left.value + new.right.value
    return new
}

