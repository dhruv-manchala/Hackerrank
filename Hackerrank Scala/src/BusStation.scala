import scala.io.StdIn.readLine

object BusStation {
  
  def main(args: Array[String]) {
    
    readLine
    val L = readLine.split(" ").map(_.toInt).toList
       
    val min = L.min
    val max = L.max
    val sum = L.foldRight(0)(_ + _)
    
    (max to sum by min).filter(sum % _ == 0).foreach(validBusSize(_, L, 0)) 
  }
  
  def validBusSize(size: Int, L: List[Int], curr: Int) {
 
    L match {        
      case Nil if (curr == size) => print(size + " ") 
      case head::tail if (curr < size) => 
      	validBusSize(size, tail, curr + head)
      case head::tail if (curr == size) => validBusSize(size, tail, head)
      case head::tail if (curr > size) => return
    }
  }
}