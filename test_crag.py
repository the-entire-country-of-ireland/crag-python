import fast_braids

N = 10
w1 = fast_braids.createBraid([1,5,4,4,5,-2,3,7,8])
w2 = fast_braids.createBraid([1,2,3,5,2,3,-4,5,1])

x = fast_braids.LNF(w1, N)
w = x.getBraid()

print(w)

print(w.toVector())

Ps = x.getPermutations()
for p in Ps:
	print(p)

