import pygame
import random as rnd
import socket
import time

class Telemetry(object):
    def __init__(self, n):
        self.x = 0  # absolute X position
        self.y = 0  # absolute Y position

        self.px = 0 # previous mouse X position
        self.py = 0 # previous mouse Y position

        self.roll = 0 # used to scroll text
        self.maxscroll = 0 # used to scroll text

        self.number = n
        self.name = "B" + str(n) # robot name
        # Selects the robots color...
        if n == 1:
            self.color = (255, 0, 0)
        elif n == 2:
            self.color = (0, 255, 255)
        elif n == 3:
            self.color = (255, 255, 0)
        elif n == 4:
            self.color = (255, 0, 255)

        self.size = 90 # screen size

        self.minimize = False    # toogles the minimized screen
        self.hide = False        # toogles the hidden variables

        # Variables to be shown in the window
        self.variables = [['SOMETHING1', True, 'void'],
                          ['SOMETHING2', False, 'void'],
                          ['SOMETHING3', True, 'void']]

        self.othervars = [100 * n, 100 * n, 30 * n, 20 * n] # The sequence is X, Y, Rotation and Standard Deviation

        self.resizing = False   # toogles the resizing function
        self.dragging = False    # toogles the dragging function

        self.font = pygame.font.SysFont('Arial', 12)

        self.timestamp = time.time()

        self.Body = pygame.Surface((260, 742), pygame.SRCALPHA) # surface to draw the interactive window
        self.Robot = pygame.Surface((26,26), pygame.SRCALPHA) # surface to draw robot

    def change(self, data): # Distributes the received messages into the variables.
        self.othervars[0] = float(data[1])
        self.othervars[1] = float(data[2])
        self.othervars[2] = float(data[3])
        self.othervars[3] = float(data[4])
        self.variables[1][2] = data[5]
        self.variables[2][2] = data[6]
        self.timestamp = time.time()

    def timeout(self): # Returns how long since the last received message
        timer = time.time() - self.timestamp
        return timer

    def draw(self, where):
        new = pygame.Surface((1042, 742), pygame.SRCALPHA) # Surface of the Telemetry

        pygame.draw.line(new, self.color,(int((2*self.x+260)/2),int((2*self.y+20+self.size*(not(self.minimize)))/2)),(int(self.othervars[0]),int(self.othervars[1])), 3) # Draws a line
        pygame.draw.rect(new, (0,0,0,0), (self.x, self.y, 260, 20+self.size*(not(self.minimize))), 0) # Cuts a square
        pygame.draw.circle(new, (0,0,0,0), (int(self.othervars[0]), int(self.othervars[1])), int(self.othervars[3]), 0) # Cuts a circle
        pygame.draw.circle(new, self.color, (int(self.othervars[0]), int(self.othervars[1])), int(self.othervars[3]), 3) # Draws a circle

        self.Body.fill(pygame.Color(255,255,255,0)) # Clear the window surface
        self.Robot.fill(pygame.Color(255,255,255,0)) # Clear the robot surface

        # Draws the robot
        pygame.draw.rect(self.Robot, self.color + (150,), (3, 0, 16, 26), 0) # Fill Body
        pygame.draw.rect(self.Robot, (0, 0, 0), (3, 0, 16, 26), 1) # Countour Body
        pygame.draw.rect(self.Robot, (0, 0, 0, 150), (19, 2, 5, 10), 0) # Fill feet
        pygame.draw.rect(self.Robot, (0, 0, 0, 150), (19, 14, 5, 10), 0)
        pygame.draw.rect(self.Robot, (0, 0, 0), (19, 2, 5, 10), 1) # Countour feet
        pygame.draw.rect(self.Robot, (0, 0, 0), (19, 14, 5, 10), 1)

        # Rotates robot
        aux = pygame.transform.rotate(self.Robot, self.othervars[2])
        rr = aux.get_rect()

        if self.dragging:
            self.drag()     # Drags the object around
        if self.resizing:
            self.resize()   # Resizes the object

        if self.minimize:
            pygame.draw.rect(self.Body, (0,0,0,150), (0,0,260,20))
            pygame.draw.line(self.Body, (255,255,255), (249, 4), (249, 15), 2)
        else:
            pygame.draw.rect(self.Body, (0,0,0,150), (0,0,260,20 + self.size))
            self.Write()
            pygame.draw.line(self.Body, (0,0,0), (0,0), (0,19 + self.size), 2)
            pygame.draw.line(self.Body, (0,0,0), (258,0), (258,19 + self.size), 2)
            pygame.draw.line(self.Body, (0,0,0), (0,17 + self.size), (260,17 + self.size), 5)

        if self.hide:
            pygame.draw.line(self.Body, (255,255,255), (227,4), (227,15), 2)
            pygame.draw.line(self.Body, (255,255,255), (231,4), (231,15), 2)
            pygame.draw.line(self.Body, (255,255,255), (227,9), (232,9), 2)
        else:
            pygame.draw.rect(self.Body, (255,255,255), (224,4,11,11), 0)

        pygame.draw.line(self.Body, (255,255,255), (244, 9), (255, 9), 2)
        pygame.draw.rect(self.Body, (255,255,255), (244,4,11,11), 2)
        pygame.draw.rect(self.Body, (255,255,255), (224,4,11,11), 2)

        self.font.set_bold(True)
        self.Body.blit(self.font.render(self.name, 1, self.color), (10, 4))

        pygame.draw.rect(self.Body, (0,0,0), (0,0,259,19), 2)

        new.blit(aux, (int(self.othervars[0]-rr[2]/2), int(self.othervars[1]-rr[3]/2))) # Draws the Robot
        new.blit(self.Body, (int(self.x), int(self.y))) # Draws the object on screen
        where.blit(new, (0,0)) # Draws Telemetry on Screen

    def Write(self):
        pos = self.roll # initial text position

        self.font.set_bold(False) # toogles off bold font

        TextBody = pygame.Surface((260, self.size), pygame.SRCALPHA) # creates a surface for the text

        for x in self.variables: # for each variable

            if not(x[1]): # if it is not hidden
                txt = x[0] + " = " + x[2] # reads the variable in the memory...
                TextBody.blit(self.font.render(txt, 1, (255,255,255)), (10, pos)) # print the variable
                pos += 16 # makes a space

            elif not(self.hide) and x[1]: # if hidden variables are not to be hidden
                TextBody.blit(self.font.render(x[0], 1, (128,128,128)), (10, pos)) # print the variable
                pos += 16 # makes a space

        self.maxscroll = pos
        self.Body.blit(TextBody, (0,20)) # draws the texts to the window

    def click(self, mx, my):
        # Tests where is the mouse click
        if mx > self.x+244 and mx < self.x+256 and my > self.y+4 and my < self.y+16:
            self.minimize = not(self.minimize) # toogles minimized screen

        elif mx > self.x+224 and mx < self.x+236 and my > self.y+4 and my < self.y+16:
            self.hide = not(self.hide) # toogles hidden atributes

        elif not(self.minimize) and my > self.y + 10 + self.size and my < self.y + 21 + self.size:
            self.start_resize() # starts the resizing function

        elif mx > self.x and mx < self.x + 260 and not(self.minimize) and not(self.hide) and my > self.y + 20 and my < self.y + 20 + self.size:
            pos = self.roll # Positions the button tests

            for x in self.variables:
                if my > self.y+20+pos and my < self.y + pos + 36: # Verifies the position of the click
                    x[1] = not(x[1]) # toogles
                pos += 16

        else:
            self.start_drag() # starts the dragging function

    def scroll(self, up):
        # Scrolls only if there are things not seen on the screen...
        if up and not(self.minimize) and self.maxscroll > self.size:
            self.roll -= 5

        elif not(up) and not(self.minimize) and self.roll < 0:
            self.roll += 5

    def start_resize(self):
        self.px, self.py = pygame.mouse.get_pos() # Saves mouse initial position
        self.resizing = True # starts resizing

    def resize(self):
        dx, dy = pygame.mouse.get_pos() # gets actual mouse position

        self.size += dy - self.py # Compute new size

        # Checks size bounds
        if self.size < 20:
            self.size = 20
        elif self.size > 700:
            self.size = 700

        self.px, self.py = dx, dy # save actual mouse position

    def stop_resize(self):
        self.resizing = False # stops resizing

    def start_drag(self):
        self.px, self.py = pygame.mouse.get_pos() # saves mouse initial position
        self.dragging = True # starts dragging

    def drag(self):
        dx, dy = pygame.mouse.get_pos() # gets actual mouse position

        self.x += dx - self.px # Computes new X position

        # Checks X position boundaries
        if self.x < 0:
            self.x = 0
        elif self.x > 782:
            self.x = 782

        self.y += dy - self.py # Computes new Y position

        # Checks Y position boundaries
        if self.y < 0:
            self.y = 0
        elif self.y > 722:
            self.y = 722

        self.px, self.py = dx, dy # saves actual mouse position

    def stop_drag(self):
        self.dragging = False # stops dragging function

def TelemetryControl(tele, sock): # Function to Control the Telemetry Screens
    # Iterates through all ports searching messages
    for s in sock:
        try:
            data = s.recv(1024, socket.MSG_DONTWAIT) # Get's the message from the buffer
            data = data.split() # Splits it into a list
            test = True # Assumes the message is from a new robot

            for t in tele: # Iterates through all opened screens
                if t.number == int(data[0]): # Eventually if the robot exists
                    t.change(data) # Saves the received message into the Telemetry variables
                    test = False # Confirms the existing robot
                    break # Stops iterations

            if test: # If the robot was not found
                tele.append(Telemetry(int(data[0]))) # Creates a new screen to it
        except:
            pass

    pop = []
    a = 0
    for t in tele: # For all robots
        timer = t.timeout()  # Get's how long since the last received message
        if timer > 10: # If it is ore than 10 seconds
            pop.append(a) # It will be erased
        a += 1

    a = 0
    for p in pop:
        tele.pop(p-a) # Erases all robots that do not exist anymore
        a += 1 # adjust factor for pop values...
