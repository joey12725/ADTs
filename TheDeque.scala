package cs2.adt

class TheDeque[A : Manifest] extends Deque[A] {
  private class Node(var elem:A, var prev:Node, var next:Node)
  var length = 0
  private var sentinel:Node = new Node(Array.ofDim[A](1).apply(0), null, null)
  sentinel.prev = sentinel
  sentinel.next = sentinel
  def prepend(data:A):Unit = {
    if (length == 0){
      sentinel.next = new Node(data, sentinel, sentinel)
      sentinel.prev = sentinel.next
      length += 1
    }
    else {
      sentinel.next = new Node(data, sentinel, sentinel.next)
      sentinel.next.next.prev = sentinel.next
      length += 1
    }
  }
  def append(data:A):Unit = {
    if (length == 0){
      sentinel.next = new Node(data, sentinel, sentinel)
      sentinel.prev = sentinel.next
      length += 1
    }
    else {
      sentinel.prev = new Node(data, sentinel.prev, sentinel)
      sentinel.prev.prev.next = sentinel.prev
      length += 1
    }
  }
  def front():A = {
    if(length == 0){ throw new IndexOutOfBoundsException() }
    else {
      val ret = sentinel.next.elem
      var head = sentinel.next
      sentinel.next = sentinel.next.next
      head = null
      length -= 1
      ret
    }
  }
  def back():A = {
    if(length == 0){ throw new IndexOutOfBoundsException() }
    else {
      val ret = sentinel.prev.elem
      var head = sentinel.prev
      sentinel.prev = sentinel.prev.prev
      head = null
      length -= 1
      ret
    }
  }
  def peekFront():A = {
    if(length == 0){ throw new IndexOutOfBoundsException() }
    else {
      sentinel.next.elem
    }
  }
  def peekBack():A = {
    if(length == 0){ throw new IndexOutOfBoundsException() }
    else { sentinel.prev.elem
  }
}

  def isEmpty():Boolean = {length == 0}
}
