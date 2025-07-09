# Changelog
Notable changes to this project will be documented in this file.

## Compatibility
The following table lists the versions of the ibahd-api Python package in combination with different iba software.

| ibaHD-Server | ibaHD-API | ibahd-api Python package |
|--------------|-----------|--------------------------|
| v3.5.0       | v1.5.0    | v1.1.0 - v1.1.1          |

## [1.1.1] - 2025-07-09

### Bugfixes (B)
1. Fix documentation of helper functions (now consistent with Google docstring style)
2. utils.get_api_params(...): now allows Quick-Connect info as dict (new) or str (now deprecated)

## [1.1.0] - 2025-07-02

### New features (N)
1. Add helper functions:
	- utils.get_api_params(...): Retrieve API connection parameters from QuickConnect-String.
	- utils.create_client(...): Put together credentials and instantiate an gRPC client for the connection.

## [1.0.0] - 2025-07-02

First version.   
This Python package contains all the functions of the ibaHD-API and simplifies their usage in the Python programming language.
