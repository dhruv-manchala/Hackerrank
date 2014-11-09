import scala.runtime.ScalaRunTime.stringOf
import scala.io.StdIn.readLine

object SherlockAndWatson {
  
  def main(args: Array[String]) {

    val Array(_, k, q) = readLine.split(" ").map(_.toInt)
    var A = readLine.split(" ").map(_.toInt)
    
    rotate(A, k)
    
    for (i <- 0 to q - 1) {
    	val ind = readLine.toInt
    	println(A(ind))
    }
  }
  
  def reverse(A: Array[Int], start: Int, end: Int) {
    
    if (start >= end) return
    else {      
      
      val temp = A(start)
      A(start) = A(end)
      A(end) = temp
      
      reverse(A, start + 1, end - 1)
    }
  }
  
  def rotate(A: Array[Int], k: Int) {
    
    val len = A.length
    val k_ = k % len
    
    reverse(A, 0, len - 1 - k_)
    reverse(A, len - k_, len - 1)
    reverse(A, 0, len - 1)
  }
}