from phenomena.connection import OSCPhenomenaServer
from phenomena.nodes import getNodeController
if __name__ == '__main__':
    server = OSCPhenomenaServer(getNodeController())
    server.startServer()

