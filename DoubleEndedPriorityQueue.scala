package cs2.adt

class DEPQ[A <% Ordered[A] : Manifest] extends DoubleEndPriorityQueue[A] {
  class Node (var data: A, var last: Node, var next: Node)

  var sentinel:Node = new Node(Array.ofDim[A](1).apply(0), null, null)
  sentinel.last = sentinel
  sentinel.next = sentinel

  def isEmpty():Boolean = { sentinel.next == null }
  def peekMax():A = { sentinel.next.data }
  def peekMin():A = { sentinel.last.data }

  def add(elem: A):Unit = {
    if(sentinel.next == null){
      sentinel.next = new Node(elem, sentinel, sentinel)
      sentinel.last = sentinel.next
    }
    else if(elem > sentinel.next.data){
      sentinel.next.last = new Node(elem, sentinel, sentinel.next)
      sentinel.next = sentinel.next.last
    }
    else if(elem < sentinel.next.data){
      var rover:Node = sentinel
      while( rover.next.data >= elem && rover.next != null ){
        rover = rover.next
      }
      rover.next = new Node(elem, rover.next.last, rover.next)
      rover.next = rover.next.last.next
      rover.next = rover.next.next.last
    }
  }
  def max():A = {
    var ret = sentinel.next.data
    var head = sentinel.next
    sentinel.next = sentinel.next.next
    head == null
    ret
  }

  def min():A = {
      var returnData = sentinel.last.data
      var end = sentinel.last
      sentinel.last = sentinel.last.last
      end == null
      returnData
    }
  }
