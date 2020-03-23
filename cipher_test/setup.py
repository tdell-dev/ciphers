# Always prefer setuptools over distutils
from setuptools import setup, find_packages
from os import path

here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

# Arguments marked as "Required" below must be included for upload to PyPI.
# Fields marked as "Optional" may be commented out.

setup(
    name='cipher_test',                                                            # Required
    version='0.0.0',                                                               # Required
    description='A repository for sim tests in cocotb',                            # Optional
    long_description=long_description,                                             # Optional
    long_description_content_type='text/markdown',                                 # Optional (see note above)
    packages=find_packages(exclude=['contrib', 'docs', 'tests']),                  # Required
    python_requires='>=3.5.*, <4',                                                 # Optional
    setup_requires=['wheel']
)
