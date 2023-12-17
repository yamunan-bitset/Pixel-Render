from pygame import gfxdraw

def point(screen, xy, col, size=25):
    for i in range(size):
        for j in range(size):
            gfxdraw.pixel(screen, xy[0] + i, xy[1] + j, col)

def render_from_file(arr, screen, col):
    x = 50
    y = 50
    for i in range(6):
        y += 25
        for j in range(5):
            x += 25
            if arr[i][j] == 1:
                point(screen, (x, y), col, 25)
            else:
                point(screen, (x, y), (0, 0, 255), 25)
        x = 50
