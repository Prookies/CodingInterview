cmake_minimum_required(VERSION 2.8)

project(CodingInterview2)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O0 -march=native")
add_definitions(-DCOMPILEDWITHC11)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/Utilities
    ${PROJECT_SOURCE_DIR}/src/35_CopyComplexList
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED
    src/Utilities/list.cc
    src/Utilities/binaryTree.cc
    src/Utilities/Array.cc
    src/Utilities/StringUtil.cc
    src/Utilities/Tree.cc
)

# 查找数组重复的元素
add_executable(findDuplicate src/FindDuplicate/findDuplicate.cc)
# 不修改原始数组查找重复数据
add_executable(findDuplicateNoEdit src/FindDuplicate/findDuplicateNoEdit.cc)
# 二维数组的查找
add_executable(findInPartiallySortedMatrix src/FindInPartiallySortedMatrix/findInPartiallySortedMatrix.cc)
# 替换空格字符
add_executable(replaceSpaces src/ReplaceSpaces/replaceSpaces.cc)
# 从尾到头打印链表
add_executable(printListInReversedOrder src/PrintListInReversedOrder/printListInReversedOrder.cc)
target_link_libraries(printListInReversedOrder ${PROJECT_NAME})
# 重建二叉树
add_executable(constructBinaryTree src/ConstructBinaryTree/constructBinaryTree.cc)
target_link_libraries(constructBinaryTree ${PROJECT_NAME})
# 二叉树的下一个节点
add_executable(nextNodeInBinaryTrees src/NextNodeInBinaryTrees/nextNodeInBinaryTrees.cc)
# 用两个栈实现队列
add_executable(queueWithTwoStacks src/QueueWithTwoStacks/queueWithTwoStacks.cc src/QueueWithTwoStacks/Queue.h)
# 斐波那契数列
add_executable(fibonacci src/Fibonacci/fibonacci.cc)
# 旋转数组的最小数字
add_executable(minNumberInRotatedArray src/MinNumberInRotatedArray/minNumberInRotatedArray.cc)
# 矩阵中的路径
add_executable(stringPathImMatrix src/StringPathInMatrix/stringPathInMatrix.cc)
# 机器人的运动范围
add_executable(robotMove src/13_RobotMove/robotMove.cc)
# 剪绳子
add_executable(cuttingRope src/14_CuttingRope/cuttingRope.cc)
# 二进制中1的个数
add_executable(numberOf1InBinary src/15_NumberOf1InBinary/numberOf1InBinary.cc)
# 数值的整数次方
add_executable(power src/16_Power/power.cc)
# 打印1到最大的n
add_executable(print1ToMaxOfNDigits src/17_Print1ToMaxOfNDigits/print1ToMaxOfNDigits.cc)
# 删除链表的节点
add_executable(deleteNodeInList src/18_DeleteNodeInList/deleteNodeInList.cc)
target_link_libraries(deleteNodeInList ${PROJECT_NAME})
# 删除链表中重复的节点
add_executable(deleteDuplicatedNode src/18_DeleteNodeInList/deleteDuplicatedNode.cc)
target_link_libraries(deleteDuplicatedNode ${PROJECT_NAME})
# 正则表达式匹配
add_executable(regularExpressions src/19_RegularExpressionsMatching/regularExpressions.cc)
# 表示数值的字符串
add_executable(numericString src/20_NumericStrings/numericString.cc)
# 调整数组顺序使奇数位于偶数前面
add_executable(reorderArray src/21_ReorderArray/reorderArray.cc)
# 链表中倒数第k个节点
add_executable(kthNodeFromEnd src/22_KthNodeFromEnd/kthNodeFromEnd.cc)
target_link_libraries(kthNodeFromEnd ${PROJECT_NAME})
# 链表中环的入口节点
add_executable(entryNodeInListLoop src/23_EntryNodeInListLoop/entryNodeInListLoop.cc)
target_link_libraries(entryNodeInListLoop ${PROJECT_NAME})
# 反转链表
add_executable(reverseList src/24_ReverseList/reverseList.cc)
target_link_libraries(reverseList ${PROJECT_NAME})
# 合并连个排序的链表
add_executable(mergeSortedLists src/25_MergeSortedLists/mergeSortedLists.cc)
target_link_libraries(mergeSortedLists ${PROJECT_NAME})
# 树的子结构
add_executable(substructureInTree src/26_SubstructureInTree/substructureInTree.cc)
target_link_libraries(substructureInTree ${PROJECT_NAME})
# 二叉树的镜像
add_executable(mirrorOfBinaryTree src/27_MirrorOfBinaryTree/mirrorOfBinaryTree.cc)
target_link_libraries(mirrorOfBinaryTree ${PROJECT_NAME})
# 对称的二叉树
add_executable(symmetricalBinaryTree src/28_SymmetricalBinaryTree/symmetricalBinaryTree.cc)
target_link_libraries(symmetricalBinaryTree ${PROJECT_NAME})
# 顺时针打印矩阵
add_executable(printMatrix src/29_PrintMatrix/printMatrix.cc)
target_link_libraries(printMatrix ${PROJECT_NAME})
# 包含min函数的栈
add_executable(minInStack src/30_MinInStack/MinInStack.cc src/30_MinInStack/StackWithMin.h)
# 栈的压入、弹出序列
add_executable(stackPushPopOder src/31_StackPushPopOrder/StackPushPopOrder.cc)
# 从上到下打印二叉树1
add_executable(printTreeFromTopToBottom src/32_PrintTreeFromTopToBottom/PrintTreeFromTopToBottom_1.cc)
target_link_libraries(printTreeFromTopToBottom ${PROJECT_NAME})
# 分行从上到下打印二叉树
add_executable(printTreesInLines src/32_PrintTreeFromTopToBottom/printTreesInLines.cc)
target_link_libraries(printTreesInLines ${PROJECT_NAME})
# 之字形打印二叉树
add_executable(printTreesInZigzag src/32_PrintTreeFromTopToBottom/PrintTreesInZigzag.cc)
target_link_libraries(printTreesInZigzag ${PROJECT_NAME})
# 二叉搜索树的后序遍历序列
add_executable(squenceOfBST src/33_SquenceOfBST/SquenceOfBST.cc)
# 二叉树中和为某一值的路径
add_executable(pathInTree src/34_PathInTree/PathInTree.cc)
target_link_libraries(pathInTree ${PROJECT_NAME})
# 复杂链表的复制
add_library(complexList SHARED
    src/35_CopyComplexList/ComplexList.cc
)
add_executable(copyComplexList src/35_CopyComplexList/CopyComplexList.cc)
target_link_libraries(copyComplexList complexList)
# 二叉搜索树与双向链表
add_executable(convertBinarySearchTree src/36_convertBinarySearchTree/ConvertBinarySearchTree.cc)
target_link_libraries(convertBinarySearchTree ${PROJECT_NAME})
# 序列化二叉树
add_executable(serializeBinaryTrees src/37_SerializeBinaryTrees/SerializeBinaryTrees.cc)
target_link_libraries(serializeBinaryTrees ${PROJECT_NAME})
# 字符串的排列
add_executable(stringPermutation src/38_StringPermutation/StringPermutation.cc)
# 数组中有一个数字出现次数超过数组长度的一半，请找出这个数字
add_executable(moreThanHalfNumber src/39_MoreThanHalfNumber/MoreThanHalfNumber.cc)
target_link_libraries(moreThanHalfNumber ${PROJECT_NAME})
# 输入n个整数，找出其中最下的k个数
add_executable(kLeastNumbers src/40_KLeastNumbers/KLeastNumbers.cc)
target_link_libraries(kLeastNumbers ${PROJECT_NAME})
# 数据流中的中位数
add_executable(streamMedian src/41_StreamMedian/StreamMedian.cc)
# 连续子数组的最大和
add_executable(greatestSumOfSubarrays src/42_GreatestSumOfSubarrays/GreatestSumOfSubarrays.cc)
# 从1到n整数中1出现的次数
add_executable(numberOf1 src/43_NumberOf1/NumberOf1.cc)
# 数字序列中某一位的数字
add_executable(digitsInSequence src/44_DigitsInSequence/DigitsInSequence.cc)
# 把数组排成最小的数
add_executable(sortArrayForMinNumber src/45_sortArrayForMinNumber/SortArrayForMinNumber.cc)
# 把数字翻译成字符串
add_executable(translateNumbersToStrings src/46_TranslateNumbersToStrings/TranslateNumbersToStrings.cc)
# 礼物的最大价值
add_executable(maxValueOfGifts src/47_MaxValueOfGifts/MaxValueOfGifts.cc)
# 最长不重复字符的子字符串
add_executable(longestSubstringWithoutDup src/48_LongestSubstringWithoutDup/LongestSubstringWithoutDup.cc)
# 丑数
add_executable(uglyNumber src/49_UglyNumber/UglyNumber.cc)
# 字符串中第一个只出现一次的字符
add_executable(firstNotRepeatingChar src/50_FirstNotRepeatingChar/FirstNotRepeatingChar.cc)
# 字符流中第一个只出现一次的字符
add_executable(firstCharacterInStream src/50_FirstNotRepeatingChar/FirstCharacterInStream.cc)
# 数组中的逆序对
add_executable(inversePairs src/51_InversePairs/InversePairs.cc)
# 两个链表的第一个公共节点
add_executable(firstCommonNodesInLists src/52_FirstCommonNodesInLists/FirstCommonNodesInLists.cc)
target_link_libraries(firstCommonNodesInLists ${PROJECT_NAME})
# 数字在排序数组中出现的次数
add_executable(numberOfK src/53_NumberOfK/NumberOfK.cc)
# 0到n-1中缺失的数字
add_executable(missingNumber src/53_NumberOfK/MissingNumber.cc)
# 数组中数值和下标相等的元素
add_executable(integerIdenticalToIndex src/53_NumberOfK/IntegerIdenticalToIndex.cc)
add_executable(kthNodeInBST src/54_KthNodeInBST/KthNodeInBST.cc)
target_link_libraries(kthNodeInBST ${PROJECT_NAME})
# 二叉树的深度
add_executable(treeDepth src/55_01_TreeDepth/TreeDepth.cc)
target_link_libraries(treeDepth ${PROJECT_NAME})
# 平衡二叉树
add_executable(balancedBianryTree src/55_02_BalancedBianryTree/BalancedBianryTree.cc)
target_link_libraries(balancedBianryTree ${PROJECT_NAME})
# 数组中只出现一次的两个数字
add_executable(numbersAppearOnce src/56_01_NumbersAppearOnce/NumbersAppearOnce.cc)
# 数组中唯一只出现一次的数字
add_executable(numberAppearingOnce src/56_02_NumberAppearingOnce/NumberAppearingOnce.cc)
# 和为s的两个数字
add_executable(twoNumbersWithSum src/57_01_TwoNumbersWithSum/TwoNumbersWithSum.cc)
# 和为s的连续正数序列
add_executable(continuousSqueueWithSum src/57_02_ContinuousSqueueWithSum/ContinuousSqueueWithSum.cc)
# 翻转单词顺序
add_executable(reverseWordsInSentence src/58_01_ReverseWordsInSentence/ReverseWordsInSentence.cc)
target_link_libraries(reverseWordsInSentence ${PROJECT_NAME})
# 左旋转字符串
add_executable(leftRotateString src/58_02_LeftRotateString/LeftRotateString.cc)
target_link_libraries(leftRotateString ${PROJECT_NAME})
# 滑动窗口的最大值
add_executable(maxInSlidingWindow src/59_01_MaxInSlidingWindow/MaxInSlidingWindow.cc)
# 队列的最大值
add_executable(queueWithMax src/59_02_QueueWithMax/QueueWithMax.cc)
# n个骰子的点数
add_executable(dicesProbability src/60_DicesProbability/DicesProbability.cc)
# 扑克牌的顺子
add_executable(continousCards src/61_ContinousCards/ContinousCards.cc)
# 圆圈中最后剩下的数字
add_executable(lastNumberInCircle src/62_LastNumberInCircle/LastNumberInCircle.cc)
# 股票的最大利润
add_executable(maximalProfit src/63_MaximalProfit/MaximalProfit.cc)
# 求1+2+...+n
add_executable(accumulate src/64_Accumulate/Accumulate.cc)
# 不用加减乘除做加法
add_executable(addTwoNumbers src/65_AddTwoNumbers/AddTwoNumbers.cc)
# 构建乘积数组
add_executable(constArray src/66_ConstArray/ConstArray.cc)
# 把字符串转换成整数
add_executable(stringToInt src/67_StringToInt/StringToInt.cc)
# 树中两个节点的最低公共祖先
add_executable(commonParentInTree src/68_CommonParentInTree/CommonParentInTree.cc)
target_link_libraries(commonParentInTree ${PROJECT_NAME})


add_executable(testString src/Test/testString.cc)
