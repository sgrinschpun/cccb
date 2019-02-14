import logging

_logger = None
def _initialize_log():
    global _logger
    _logger = logging.getLogger()
    handler = logging.FileHandler('/var/tmp/phenomena.log')
    formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
    handler.setFormatter(formatter)
    _logger.addHandler(handler)
    _logger.setLevel(logging.INFO)

def get_logger(logger_name):
    if not _logger: _initialize_log()
    return logging.getLogger(logger_name)