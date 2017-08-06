maze = [[1,1,1,1,1,1,1],
        [1,0,0,0,0,0,3],
        [1,0,1,0,1,0,1],
        [0,0,1,0,0,0,1],
        [1,0,1,0,1,0,1],
        [1,0,0,0,0,0,1],
        [1,2,1,0,1,0,1]]
index_start = maze.index maze.reject{|i| not i.include? 2}[0]
index_finish =  maze.index maze.reject{|i| not i.include? 3}[0]
direction.each{|i| }

