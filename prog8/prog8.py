## Standard Recursive solution for the problem , O(1) Space , Number of moves = 2^n - 1 , n-> number of discs
pegs1 = {
    'A': [3,2,1],
    'B': [],
    'C': []
}

def move_discs(src , dest):
    disc = pegs1[src].pop()
    if pegs1[dest] and pegs1[dest][-1] < disc:
        raise ValueError("Illegal move")
    pegs1[dest].append(disc)


def hanoi_rec(n , src , dest ,temp):
    if n==0:
        return
    hanoi_rec(n-1,src , temp , dest)
    move_discs(src , dest)
    hanoi_rec(n-1 , temp , dest , src)
    
hanoi_rec(3 ,'A' , 'C' , 'B' )
print(pegs1)


## The iterative approach utilises the unique property of gray coded discrete values from 1 to 2^n+1 , that indicates which disc moves
## using which we determine the direction to move the disc , depending on the parity of the disc and the n.

pegs2 = {
    0: [3,2,1],
    1: [],
    2: []
}## Must take indices as keys , since you are calculating to distance of the source and destination pegs , making alphabetical labelling ineffective

def find_peg(disc): #helper function to get the peg , that a particular disc is located in
    for i in pegs2:
        if disc in pegs2[i]:
            return i
def hanoi_iter(n):
    total = (1<<n) - 1 ## Total number of moves = 2^n - 1
    for i in range(1,total+1):
        disc = (i&-i).bit_length() #obtaining the lowest sit bit via the bit.length() function , after adding the opposite signed integers , to obrain disc to move
        dir = (-1 if (n+disc)%2 == 0 else +1) #you are moving the discs from the 0 peg to the last peg in the table , which is 2 , effectively index -1 , so -1 if the parity is even , else +!

        src_peg = find_peg(disc)
        dest_peg = (src_peg+dir+3)%3 ## we add 3 and mod by 3 , to remove possible negative values arising from using -1 as a valid direction , to obtain a valid key for destination peg

        pegs2[dest_peg].append(pegs2[src_peg].pop())

hanoi_iter(3)
print(pegs2)

#output {0:[] , 1:[] , 2:[3,2,1]}