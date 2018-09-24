from cyaron import *

PATH = "C:\\Users\\kriae\\Desktop\\Tsuki\\std.exe"

if __name__ == '__main__':
  for i in range(1, 5):
    data = IO(file_prefix = 'tsuki', data_id = i)
    n = 5000
    Q = 5000
    tree = Graph.tree(n, repeated_edges = False)
    data.input_writeln(n, Q)
    data.input_writeln(tree.to_str(shuffle = True, output = Edge.unweighted_edge))
    for j in range(1, Q + 1):
      l = randint(1, n)
      r = randint(1, n)
      if l > r:
        l, r = r, l
      data.input_writeln(l, r)
    data.output_gen(PATH)
  for i in range(5, 7):
    data = IO(file_prefix = 'tsuki', data_id = i)
    n = 100000
    Q = 100000
    tree = Graph.tree(n, repeated_edges = False)
    data.input_writeln(n, Q)
    data.input_writeln(tree.to_str(shuffle = True, output = Edge.unweighted_edge))
    for j in range(1, Q + 1):
      l = 1
      r = randint(1, n)
      data.input_writeln(l, r)
    data.output_gen(PATH)
  for i in range(7, 8):
    data = IO(file_prefix = 'tsuki', data_id = i)
    n = 100000
    Q = 100000
    tree = Graph.tree(n, 0.1, 0.9, repeated_edges = False)
    data.input_writeln(n, Q)
    data.input_writeln(tree.to_str(shuffle = True, output = Edge.unweighted_edge))
    for j in range(1, Q + 1):
      l = randint(1, n)
      r = randint(1, n)
      if l > r:
        l, r = r, l
      data.input_writeln(l, r)
    data.output_gen(PATH)
  for i in range(8, 9):
    data = IO(file_prefix = 'tsuki', data_id = i)
    n = 100000
    Q = 100000
    tree = Graph.tree(n, 0.9, 0.1, repeated_edges = False)
    data.input_writeln(n, Q)
    data.input_writeln(tree.to_str(shuffle = True, output = Edge.unweighted_edge))
    for j in range(1, Q + 1):
      l = randint(1, n)
      r = randint(1, n)
      if l > r:
        l, r = r, l
      data.input_writeln(l, r)
    data.output_gen(PATH)
  for i in range(9, 11):
    data = IO(file_prefix = 'tsuki', data_id = i)
    n = 100000
    Q = 100000
    tree = Graph.tree(n, repeated_edges = False)
    data.input_writeln(n, Q)
    data.input_writeln(tree.to_str(shuffle = True, output = Edge.unweighted_edge))
    for j in range(1, Q + 1):
      l = randint(1, n)
      r = randint(1, n)
      if l > r:
        l, r = r, l
      data.input_writeln(l, r)
    data.output_gen(PATH)