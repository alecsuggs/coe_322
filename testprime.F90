program primes
  implicit none
  integer :: how_many
  integer :: num_primes_found = 0
  integer :: j = 2
  logical :: prime
  read*,how_many
  do while (num_primes_found<how_many)
     prime = test_if_prime(j)
     if (prime) then
        print*,j
        num_primes_found=num_primes_found+1
     end if
     j=j+1
  end do
contains
  logical function test_if_prime(num)
    implicit none
    integer :: num
    integer ::  i
    logical :: prime
    test_if_prime = .true.
    do i=2,num/2
       if (mod(num,i)==0) then
          test_if_prime = .false.
       end if
    end do
  end function test_if_prime
end program primes
