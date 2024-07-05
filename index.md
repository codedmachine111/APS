**Course Name:** Algorithmic Problem Solving  
**Course Code:** 23ECSE309  
**Name:** Akash Nayak  
**SRN:** 01FE21BEC263   
**University:** KLE Technological University, Hubballi-31  
**Portfolio domain:** Youtube   

## Introduction

YouTube is the world's largest video-sharing platform and operates on a very complex technological infrastructure. With over 2 billion monthly active users, more than 500 hours of videos are posted to YouTube every minute. Daily views of YouTube Shorts, a feature for short video content, are 15 billion. YouTube launched a $100 million Shorts Fund to entice Creators to experiment with producing short-form videos. Approximately 30,000 hours of video are uploaded to YouTube every hour by artists. Every week, 92% of internet users watch some form of YouTube video. YouTube also has the second-largest search engine in the world. Branded searches make up 52% of the top 100 queries. Leading countries based on YouTube audience size are the US, India, Japan, and Indonesia.

The smooth experience that users and creators enjoy is possible due to a variety of data structures and algorithms working under the hood. These technologies ensure efficient data management, personalized recommendations, optimized streaming, and much more. This portfolio explores the critical role of various data structures and algorithms that can potentially enhance YouTube's features and functionalities. By examining existing and potential use cases for these technologies, this portfolio aims to provide a comprehensive understanding of their impact on the platform.

### Objectives

- Categorize features and underlying technologies of YouTube.
- Identify key algorithms, data structures, or system design techniques currently in use or with potential applications in enhancing YouTube's features.
- Create a resource that can be used for educational purposes to understand the intersection of data structures, algorithms, and real-world applications in a large-scale platform like YouTube.

### Journey of the content

Let's explore the journey of a video from the creator to the viewer before we explore the business cases involved at each step. There are three stakeholders in the content lifecycle: The **Creators** who record, edit, and upload videos; the **YouTube platform** where the video is uploaded and stored in the data centers; and finally, the **Viewers** who watch the video.

Initially, when the creator tries to upload a video to YouTube, the file is directed to **Upload servers** which facilitate the process of uploading the file from client's device to a BLOB storage. After the video is uploaded and stored, they are fetched by the **Transcoding server** for processing and encoding the video to different bitrates and formats. The transcoded videos are distributed to Content Delivery Networks (CDNs) which are geographically placed. When a viewer starts streaming a video, they get the first segment of that video from the nearest CDN and streaming protocols like MPEG-DASH help stream segments adaptively based on the viewer's network bandwidth.

#### References
- [YouTube Market Stats](https://www.simplilearn.com/youtube-marketing-stats-article)
