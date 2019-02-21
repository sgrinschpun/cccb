from sys import platform
from setuptools import find_packages
from os.path import expanduser, join
from setuptools import setup
HOME = expanduser("~")

INSTALL_PATH = join(HOME, '.phenomena')
CONFIG_PATH = join(INSTALL_PATH, 'conf')

#data_files = [(CONFIG_PATH, ["other/config/part_extra_info.json", 
#                            "other/config/mass_width_2017.mcd",
#                            "other/config/inelastic_2body_data.json"])]

data_files = []
packages = ['phenomena']
setup_args = {
        'name': 'phenomena',
        'version': '0.1',
        'packages': find_packages(),
        'data_files': data_files,
        'include_package_data': True,
        'install_requires': ["mido", "python-osc",
                    'pkgconfig', 
                    'atomicwrites==1.2.1',
                    'attrs==18.2.0',
                    'cycler==0.10.0',
                    'decaylanguage==0.2.0',
                    'funcsigs==1.0.2',
                    'importlib-resources==1.0.1',
                    'more-itertools==4.3.0',
                    'numpy==1.15.2',
                    'pandas==0.23.4',
                    'particletools==1.0.0rc6',
                    'pathlib2==2.3.2',
                    'pluggy==0.8.0',
                    'plumbum==1.6.7',
                    'py==1.7.0',
                    'pynput==1.4',
                    'pyparsing==2.2.2',
                    'PyPDT==0.7.4',
                    'pytest==3.9.3',
                    'python-dateutil==2.7.3',
                    'pytz==2018.5',
                    'PyYAML==3.13',
                    'scandir==1.9.0',
                    'scikit-hep==0.3.0',
                    'six==1.11.0',
                    'subprocess32==3.5.3',
                    'typing==3.6.6']
        }

setup(**setup_args)
