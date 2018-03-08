import pygame
pygame.init()
BLACK    = (   0,   0,   0)
WHITE    = ( 255, 255, 255)
GREEN    = (   0, 255,   0)
RED      = ( 255,   0,   0)
BLUE     = (   0,   0, 255)

size = (700,500)
screen= pygame.display.set_mode(size)

pygame.display.set_caption("professeor blabla")

done= False
clock = pygame.time.Clock()

while not done:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			done= True
	#game logic
	#drawing

	screen.fill(WHITE)
	pygame.display.flip()
	clock.tick(60)		
