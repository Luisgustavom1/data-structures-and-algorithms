import turtle

WALL = "+"
VISITED = "."
PART_OF_PATH = 'O'
DEAD_END = '-'

class Maze:
  def __init__(self, mazeFileName):
    self.maze = []
    mazeFile = open(mazeFileName,'r')

    self.rows = 0
    for line in mazeFile:
        row = []
        col = 0
        for ch in line[:-1]:
            row.append(ch)
            if ch == 'S':
                self.startRow = self.rows
                self.startCol = col
            col += 1

        self.rows += 1

        self.maze.append(row)
        self.cols = col
    
    self.xTranslate = -self.cols/2
    self.yTranslate = self.rows/2

    self.t = turtle.Turtle()
    self.t.shape('turtle')
    self.wn = turtle.Screen()
    self.wn.setworldcoordinates(
        -(self.cols-1)/2-.5, 
        -(self.rows-1)/2-.5, 
        (self.cols-1)/2+.5, 
         (self.rows-1)/2+.5
    )

  def updatePosition(self, r, c, value = None):
    if value:
      self.maze[r][c] = value
    
    self.moveTurtle(r, c)

    if value == PART_OF_PATH:
        color = 'green'
    elif value == WALL:
        color = 'red'
    elif value == VISITED:
        color = 'black'
    elif value == DEAD_END:
        color = 'red'
    else:
        color = None

    if color:
      self.dropBreadcrumb(color)

  def moveTurtle(self, r, c):
    self.t.up()
    self.t.setheading(self.t.towards(c+self.xTranslate,-r+self.yTranslate))
    self.t.goto(c+self.xTranslate,-r+self.yTranslate)

  def dropBreadcrumb(self,color):
    self.t.dot(10,color)

  def drawMaze(self):
    self.t.speed(10)
    self.wn.tracer(0)
    for r in range(self.rows):
        for c in range(self.cols):
            if self.maze[r][c] == WALL:
                self.drawCenteredBox(c+self.xTranslate,-r+self.yTranslate,'orange')
    self.t.color('black')
    self.t.fillcolor('blue')
    self.wn.update()
    self.wn.tracer(1)

  def drawCenteredBox(self, x, y, color):
    self.t.up()
    self.t.goto(x-.5,y-.5)
    self.t.color(color)
    self.t.fillcolor(color)
    self.t.setheading(90)
    self.t.down()
    self.t.begin_fill()
    for _ in range(4):
        self.t.forward(1)
        self.t.right(90)
    self.t.end_fill()

  def isExit(self, r, c):
    return r == 0 or c == 0 or r == self.rows - 1 or c == self.cols - 1
  
  def __getitem__(self,idx):
    return self.maze[idx]


def searchFrom(m, r, c):
  if m[r][c] == VISITED or m[r][c] == DEAD_END or m[r][c] == WALL:
    return False
  
  m.updatePosition(r, c)

  if m.isExit(r, c):
    m.updatePosition(r, c, PART_OF_PATH)
    return True

  m.updatePosition(r, c, VISITED)

  found = searchFrom(m, r-1, c) or \
    searchFrom(m, r+1, c) or \
    searchFrom(m, r, c-1) or \
    searchFrom(m, r, c+1)

  if found:
    m.updatePosition(r, c, PART_OF_PATH)
  else:
    m.updatePosition(r, c, DEAD_END)

  return found

myMaze = Maze("maze.txt")
myMaze.drawMaze()
myMaze.updatePosition(myMaze.startRow,myMaze.startCol)

searchFrom(myMaze, myMaze.startRow, myMaze.startCol)