import scala.io.StdIn.readLine

object ServiceLane {
  
  def main(args: Array[String]) {

	val t = readLine.split(" ")(1).toInt
    val A = readLine.split(" ").map(_.toInt)
    
    for (i <- 0 to t - 1) {
      val Array(start, end) = readLine.split(" ").map(_.toInt)
      maxWidth(A, start, end, 3)
    }
  }
              
  def maxWidth(A: Array[Int], start: Int, end: Int, curr: Int) {
  
	if (start > end) println(curr)
	else if (A(start) == 1)  println(1)
	else if (curr > A(start)) maxWidth(A, start + 1, end, A(start))
	else maxWidth(A, start + 1, end, curr)
  }
     
}	