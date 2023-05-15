arr = [8, 10, 1, 30, 140, 145, 70, 19, 323, 434, 3, 69]
least = arr[0]
maxA = arr[0]
maxB = arr[1]
maxC = arr[2]
for i in range(3, len(arr)+1, 3):
  print("\nLoop ", i)
  print(maxA)
  print(maxB)
  print(maxC)
  if maxA > maxB:
    least = maxB
  else:
    least = maxA
  if least > maxC:
    least = maxC

  try:
    if maxA < arr[i]:
      maxA = arr[i]
  except IndexError:
    pass
  try:
    if maxB < arr[i+1]:
      maxB = arr[i+1]
  except IndexError:
    pass
  try:
    if maxC < arr[i+2]:
      maxC = arr[i+2]
  except IndexError:
    pass

print("")
print(least)

#loop i = 0
#            8, 10,  1, 3, 14, 12, 70, 1
#            ^   ^   ^
#            a   b   c
#
#            maxA = 8    #initialize
#            maxB = 10   #initialize
#            maxC = 1    #initialize
#
#loop i = 1
#            8, 10, 1, 3, 14, 12, 70, 1
#                      ^   ^  ^
#                      a   b  c
#
#            maxA = 8    #   compare if 8 is greater than 3, skip assignment
#            maxB = 14   #   compare if 10 is greater than 14, assign 14 to maxB
#            maxC = 12   #   compare if 1 is greater than 12, assign 12 to maxC
#
#loop i = 2
#            8, 10, 1, 3, 14, 12, 70, 1
#                                 ^   ^   ^
#                                 a   b   c
#
#            maxA = 70   #   compare if 8 is greater than 70, assign 70 to maxA
#            maxB = 14   #   compare if 14 is greater than 1, skip assignment
#            maxC = 12   #   c is out of bounds, skip assignment
#
#stop the loop
#
#compare the values of maxA, maxB, maxC 
#maxC is the third max, return maxC