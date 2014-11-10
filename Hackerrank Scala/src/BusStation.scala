import scala.io.StdIn.readLine

object BusStation {
  
  def main(args: Array[String]) {
    readLine
    val L = readLine.split(" ").map(_.toInt).toList
    validBusSizes(L)
  }
  
  def validBusSizes(L: List[Int]) {
    
    def validBusSize(size: Int, L: List[Int], curr: Int): Boolean = {
 
      L match {        
        case Nil => return curr == size
        case head::tail if (curr < size) => 
          return validBusSize(size, tail, curr + head)
        case head::tail if (curr == size) =>
          return validBusSize(size, tail, head)
        case head::tail if (curr > size) => return false
      }
    }
    
    val min = L.max
    val max = L.foldRight(0)(_ + _)
    
    for (i <- min to max + 1) {
      if (max % i == 0) {
        if (validBusSize(i, L, 0)) print(i + " ")
      }
    }
  }

}