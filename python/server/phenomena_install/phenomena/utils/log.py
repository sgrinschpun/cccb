import logging
from logging.handlers import RotatingFileHandler
_logger = None
path = '/var/tmp/phenomena.log'
def _initialize_log():
    global _logger
    _logger = logging.getLogger()
    #handler = logging.FileHandler('/var/tmp/phenomena.log')
    handler = RotatingFileHandler(path, maxBytes=20000000, backupCount=5)
    formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
    handler.setFormatter(formatter)
    _logger.addHandler(handler)
    _logger.setLevel(logging.INFO)

def get_logger(logger_name):
    global _logger
    if not _logger: _initialize_log()
    return logging.getLogger(logger_name)