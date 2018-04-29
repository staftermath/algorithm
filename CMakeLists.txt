cmake_minimum_required(VERSION 3.10)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm
        leetcode/106.construct.binary.tree.from.inorder.and.postorder.traversal.cpp
        leetcode/113.path.sum.ii.v1.cpp
        leetcode/124.binary.tree.maximum.path.sum.v2.cpp
        leetcode/145.binary.tree.postorder.traversal.cpp
        leetcode/652.find.duplicate.subtrees.cpp
        leetcode/685.redundant.connection.ii.tle.cpp
        leetcode/814.binary.tree.pruning.cpp
        leetcode/98.validate.binary.search.tree.cpp
        notes/review_list.md leetcode/236.lowest.common.ancestor.of.a.binary.tree.cpp leetcode/61.rotate.list.cpp leetcode/24.swap.nodes.in.pairs.cpp leetcode/139.work.break.cpp leetcode/6.zigzag.conversion.cpp leetcode/127.word.ladder.v1.cpp leetcode/127.word.ladder.v2.cpp leetcode/140.word.break.ii.tle.cpp leetcode/140.word.break.ii.v2.cpp leetcode/149.max.points.on.a.line.cpp)
