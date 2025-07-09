<div align="center">

## **Package for handling Python calls to ibaHD-Servers using the ibaHD-API**
## 🎉🎉🎉 **ibahd-api v1.1.1 is now available.** 🎉🎉🎉
## `pip install --upgrade ibahd-api`

### [Tutorial][github] • [LinkedIn][LinkedIn] • [YouTube][YouTube]

| Overview      |                                                              |
|-------------- | ------------------------------------------------------------ |
| **Code**      | [![Package version](https://img.shields.io/pypi/v/ibahd-api?color=blue)][link_pypi] [![Python versions][badge_python_versions]][link_pypi] [![Semantic versioning][badge_SemVer]](https://semver.org/) |
| **Downloads** | [![pypi downloads (pepy)](https://static.pepy.tech/badge/ibahd-api/week)](https://pepy.tech/projects/ibahd-api) [![pypi downloads (pepy)](https://static.pepy.tech/badge/ibahd-api/month)](https://pepy.tech/projects/ibahd-api) ![pypi downloads (pepy)](https://static.pepy.tech/personalized-badge/ibahd-api?period=total&units=international_system&left_color=grey&right_color=blue&left_text=downloads(total)) |
| **License**   | ![License: Proprietary][badge_license_proprietary] ![Partial MIT License][badge_license_MIT] |

[link_pypi]: https://pypi.org/project/ibahd-api/
[badge_python_versions]: https://img.shields.io/pypi/pyversions/ibahd-api?color=green
[badge_SemVer]: https://img.shields.io/badge/semver-2.0.0-green
[badge_license_proprietary]: https://img.shields.io/badge/license-proprietary-blue
[badge_license_MIT]: https://img.shields.io/badge/license-partial--MIT-green

<div align="left">

# 📡 ibahd-api Python package
ibahd-api is a Python package with the aim of simplifying the access to data from the ibaHD-Server directly from inside Python code. It includes the existing functions of the ibaHD-API and extends it with some Python-specific helper functions.

The main advantage of this Python package is therefore the ease of installation and maintenance as well as the simplicity of use.

# 🚀 Installation via PyPi
ibahd-api is tested and supported on 64-bit systems with:
- Python 3.9, 3.10, 3.11 or 3.12
- Windows 10 or newer

You can install ibahd-api with Python's package manager pip.

## ⚡ Quickstart (Tutorial)
1. Install this package and all dependencies to run the tutorial notebook by using the following shell command:
```sh
> python -m pip install ibahd_api[tutorial]
```
2. Get the Jupyter Notebook `tutorial.ipynb` and the HD store backup from the [GitHub project][github].
3. In the tutorial notebook there are step-by-step instructions about how to restore the backup to your ibaHD-Server.
4. Run `tutorial.ipynb` cell by cell to get used to the ibahd-api functions and outputs.

**Note:** The tutorial does not show every single API function and does not go into detail about every single parameter. For an exhaustive list of functions and further information refer to the ibaHD-API manual which you can get from the homepage. Log in with your account and search for "api" in the [download area][Homepage Download].

## ⚡ Quickstart (General)
1. Install only this package by using the following shell command:
```sh
> python -m pip install ibahd_api
```
2. Use one of the following lines to import the package in Python and to access its functions afterwards:
```python
import ibahd_api
# ibahd_api.ibahd_api.<function>
# ibahd_api.ibahd_api_pb2_grpc.<function>

from ibahd_api import ibahd_api_pb2_grpc
# ibahd_api_pb2_grpc.<function>

from ibahd_api import *
# ibahd_api.<function>
# ibahd_api_pb2_grpc.<function>
```
3. For more information and examples for the included functions, refer to the [tutorial notebook][github] and the ibaHD-API manual. You can obtain the latter from the homepage. Log in with your account and search for "api" in the [download area][Homepage Download].

# 👥 Who should use ibahd-api?
ibahd-api is a library that you can use to extract data from an ibaHD-Server directly into Python. The package simplifies and extends the functions of the ibaHD-API and is ideal for data scientists who want to work on data from ibaHD stores in Python.

# 📄 License
This package contains components under mixed licensing terms:
- Most parts of this package are proprietary and may only be used with a valid software license.
    - See [LICENSE-PROPRIETARY.txt][github] for more information and [iba AG License Agreement][License Details] for the complete license text.
    - The proprietary license applies to the files `ibahd_api_pb2.py` and `ibahd_api_pb2_grpc.py`.
- Some files are released under the MIT License:
    - Those files may be freely used, modified, and redistributed, even independently of the rest of the package.
    - See [LICENSE-MIT.txt][github] for the complete license text.
    - The open source license applies to the file `utils.py`.
    
By installing or using this package, you agree to the applicable license terms.

# 💡 More Information

| Important Links                     |            Description                         |
| ----------------------------------- | ---------------------------------------------- |
| 🌟 **[Homepage]**                   | Company homepage of iba AG                     |
| 📄 **[License Details]**            | License for iba AG software                    |
| 🔧 **[Changelog][github]**          | Changes and release notes                      |
| 📚 **[Tutorial notebook][github]**  | Jupyter notebook showing functions examplewise |

[comment]: <> (collection of website links for easy modifiability)
[Homepage]: https://www.iba-ag.com/
[Homepage Download]: https://www.iba-ag.com/en/downloads
[LinkedIn]: https://www.linkedin.com/company/iba-ag/
[YouTube]: https://www.youtube.com/c/ibaagcom
[License Details]: https://www.iba-ag.com/en/license-agreement
[github]: https://github.com/iba-ag/ibaHD-API-Sample-Clients/tree/master/python/
