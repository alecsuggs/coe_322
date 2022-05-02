Module Pointinfo !module containing type definitions and function for area
  type point
     real(4) :: x,y
  end type point

  type rectangle
     type(point) :: lowerleft,upperright
  end type rectangle
contains
  real(4) function area(p)     !this function takes an imput type rectangle to output the area
    implicit none
    type(rectangle), intent(in) :: p
    real(4) :: distancex,distancey
    type(point) :: upright,lowleft
    upright=p%upperright
    lowleft=p%lowerleft
    distancex = upright%x-lowleft%x
    distancey = upright%y-lowleft%y
    area = distancex*distancey
  end function area
end Module Pointinfo

Program rectangle_area   !program uses module pointinfo to calculate area of axiparallel rectangle defined by two points read from user imput
  use Pointinfo
  implicit none
  type(point) :: p1,p2
  type(rectangle) :: rect
  real(4) :: a
  print *,"input two points"
  read *,p1%x,p1%y
  read *,p2%x,p2%y
  rect%lowerleft=p1
  rect%upperright=p2
  a = area(rect)
  print *,"the area of the rectangle is",a
End Program rectangle_area

