#!/usr/bin/python3
""""""
import sys


def make_board(N):
    """makes an N by N board filled with 0's"""
    board = []
    for i in range(N):
        board.append([0] * N)
    return board


def is_safe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, len(board), -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solveNQUtil(board, col, N):
    if col >= N:
        return True
    for i in range(N):
        if is_safe(board, i, col):
            board[i][col] = 1
            if solveNQUtil(board, col + 1, N) is True:
                return True
            board[i][col] = 0
    return False


def entry_point():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    board = make_board(N)
    for bi, br in enumerate(board):
        for bj, bc in enumerate(br):
            queen_tf = solveNQUtil(board, 0, N)
            # print(queen_tf)
            if queen_tf is True:
                # prints the board
                queen_loc = []
                for i, row in enumerate((board)):
                    for j, col in enumerate((row)):
                        if col == 1:
                            queen_loc.append([i, j])
                if len(queen_loc) == N:
                    print(queen_loc)
            board = make_board(N)
            board[bi][bj] = 1  # new seed for board


entry_point()
