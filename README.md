<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
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



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/RoopaPakera/5G-Dorset-Rural-Project">
    <img src="images/5G_logo.png" alt="Logo" width="180" height="70">
  </a>

<h3 align="center">5G-Dorset-Rural-Project</h3>

  <p align="left">
    Coastal landslides and cliff failures represent a significant hazard to local residents, workers and the 12 million people who visit Dorset’s coast each year. Cliff falls are a national problem which is worthy of research and development trials, as they are expensive and time consuming to monitor using traditional methods.
  <p align="left">
Our project activities to monitor land stability and cliff movement at key points along the Jurassic Coast. In order to deliver this research we have brought the British Geological Survey (BGS) into the project as a new partner who will work alongside Vodafone, Bournemouth University, Neutral Networks and Dorset Council. The work trial will deploy 5G connected NBIoT sensors to collect data, including acceleration and temperature, which will then be processed and analysed in the cloud for interpretation by BGS experts.
    <br />
    <a href="https://github.com/RoopaPakera/5G-Dorset-Rural-Project"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/RoopaPakera/5G-Dorset-Rural-Project">View Demo</a>
    ·
    <a href="https://github.com/RoopaPakera/5G-Dorset-Rural-Project/issues">Report Bug</a>
    ·
    <a href="https://github.com/RoopaPakera/5G-Dorset-Rural-Project/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
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
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![5G RuralDorset][product-screenshot]](https://5gruraldorset.org/projects/coastal-cliff-monitoring/)

Here's a blank template to get started: To avoid retyping too much info. Do a search and replace with your text editor for the following: `RoopaPakera`, `5G-Dorset-Rural-Project`, `twitter_handle`, `linkedin_username`, `email_client`, `email`, `project_title`, `project_description`

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [C++](http://www.cplusplus.org/)
* [C](https://www.learn-c.org/)
* [Python](https://www.python.org/)
* [AWS Cloud](https://aws.amazon.com/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
# Getting Started

## Raspberry Pi 

### Raspberry Pi Imaging Utility

- Download the latest version for Windows, macOS and Ubuntu from the [Raspberry Pi downloads page](https://www.raspberrypi.com/software/).
- To install on Raspberry Pi OS, use `sudo apt update && sudo apt install rpi-imager`.

### Bluetooth Adapter for rpi

If you don't have a Pi 3 you will need to use a USB Bluetooth LE dongle.

It's currently necessary to stop the (bluez) `bluetoothd` daemon as there is a conflict between how bleno and the a Bluez builtin GATT server overlap.

 
```
sudo systemctl stop bluetooth
sudo hciconfig
```

## Installation

1. Get a free Google or Amazon API Key at [https://aws.amazon.com/](https://aws.amazon.com/) or [https://console.cloud.google.com/](https://console.cloud.google.com/)
2. Clone the repo
   ```sh
   git clone https://github.com/RoopaPakera/5G-Dorset-Rural-Project.git
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Feature 1
- [ ] Feature 2
- [ ] Feature 3
    - [ ] Nested Feature

See the [open issues](https://github.com/RoopaPakera/5G-Dorset-Rural-Project/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact of contributors

Roopa Pakera - [LinkedIn](https://www.linkedin.com/in/roopa-pakera-0b48bb233/) - email@email_client.com  
Vu Dang - [LinkedIn](https://www.linkedin.com/in/vudang-2b994911b/) - dangthaihaivu1997@gmail.com

Project Link: [https://github.com/RoopaPakera/5G-Dorset-Rural-Project](https://github.com/RoopaPakera/5G-Dorset-Rural-Project)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/RoopaPakera/5G-Dorset-Rural-Project.svg?style=for-the-badge
[contributors-url]: https://github.com/RoopaPakera/5G-Dorset-Rural-Project/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/RoopaPakera/5G-Dorset-Rural-Project.svg?style=for-the-badge
[forks-url]: https://github.com/RoopaPakera/5G-Dorset-Rural-Project/network/members
[stars-shield]: https://img.shields.io/github/stars/RoopaPakera/5G-Dorset-Rural-Project.svg?style=for-the-badge
[stars-url]: https://github.com/RoopaPakera/5G-Dorset-Rural-Project/stargazers
[issues-shield]: https://img.shields.io/github/issues/RoopaPakera/5G-Dorset-Rural-Project.svg?style=for-the-badge
[issues-url]: https://github.com/RoopaPakera/5G-Dorset-Rural-Project/issues

[product-screenshot]: images/Screenshot_5G_Rural.png
