# Project: Forest-Fire-Detection

<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
<!-- [![forthebadge made-with-python](http://ForTheBadge.com/images/badges/made-with-python.svg)](https://www.python.org/) -->



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="">
    <img src="assets\readme\sharingan.jpg" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">SHARINGAN</h3>

  <p align="center">
    A Computer Vision library
    <br />
    <a href="https://github.com/SravanChittupalli/sharingan"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <!-- <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a> -->
    ·
    <a href="https://github.com/SravanChittupalli/sharingan/issues">Report Bug</a>
    ·
    <a href="https://github.com/SravanChittupalli/sharingan/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project is in accordance with the UNSDG Goal 13: Climate Change & Goal 15: Forest and Biodiversity. The motive of choosing the project for detection of forest fires is to overcome the demerits present in the existing technologies of MODIS and Basic Wireless Sensor Network based Forest Fire Detection Systems. Hence we are developing a more robust and reliable system.
The project is split into four sub-modules for step by step development and implementation. 
  1) Monitoring Area Module
  2) Forest Area Module
  3) Data Transfer Module
  4) GUI Display Module

### Built With

The repo is made with Python, Javascript, HTML and C++. We have included the following libraries:-

* [Flask](https://flask.palletsprojects.com/): Flask is a lightweight WSGI web application framework. It is designed to make getting started quick and easy, with the ability to scale up to complex applications.
* [Pyrebase](https://github.com/thisbejim/Pyrebase): A simple python wrapper for the Firebase API.
* [Chart.js](https://www.chartjs.org/): Simple yet flexible JavaScript charting for designers & developers.



<!-- GETTING STARTED -->
## Getting Started

Hardware Components: - 
  1) 1 DHT22 Temperature & Humidity Sensor
  2) 2 x Arduino Uno
  3) 2 x nRF24L01 Transreceiver Module
  4) Jumper Wires
  5) Breadboard
  6) 1 x ESP8266
  

### Prerequisites

* Anaconda/Miniconda

### Setting up

1. Clone the repo
   ```sh
   git clone https://github.com/SravanChittupalli/sharingan
   ```
2. To replicate my environment do
   ```sh
   conda env create -f environment.yml
   ``` 
   else

   If you already have an environment ready then do
   ```sh
   pip install -r requirements.txt
   ```
3. To test installation
   ```sh
   python
   import sharingan
   ``` 



<!-- USAGE EXAMPLES -->
## Usage

Please refer to the test_scripts directory

1. run the test scripts
   ```sh
   python test_negative.py
   python test_log_transform.py
   ```
2. I will be documenting everything in detail after some considerable progress is made.



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/SravanChittupalli/sharingan/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

First create an issue and discuss about the feature you want to implement. If the implementation sounds good you will be assigned to implement the feature.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Your Name - [@SChittupalli](https://twitter.com/SChittupalli) - sravanchittupalli7@gmail.com

Project Link: [https://github.com/SravanChittupalli/sharingan](https://github.com/SravanChittupalli/sharingan)






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/SravanChittupalli/sharingan.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/SravanChittupalli/sharingan.svg?style=for-the-badge
[forks-url]: https://github.com/SravanChittupalli/sharingan/network/members
[stars-shield]: https://img.shields.io/github/stars/SravanChittupalli/sharingan.svg?style=for-the-badge
[stars-url]: https://github.com/SravanChittupalli/sharingan/stargazers
[issues-shield]: https://img.shields.io/github/issues/SravanChittupalli/sharingan.svg?style=for-the-badge
[issues-url]: https://github.com/SravanChittupalli/sharingan/issues
[license-shield]: https://img.shields.io/github/license/SravanChittupalli/sharingan.svg?style=for-the-badge
[license-url]: https://github.com/SravanChittupalli/sharingan/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
