import pygame
import renderer
import arr

(width, height) = (900, 900)
screen = pygame.display.set_mode((width, height))

running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    screen.fill((255, 255, 255))
    renderer.render_from_file(arr.arr, screen, (255, 0, 0))
    pygame.display.update()
pygame.quit()
