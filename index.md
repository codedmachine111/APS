**Course Name:** Algorithmic Problem Solving  
**Course Code:** 23ECSE309  
**Name:** Akash Nayak  
**SRN:** 01FE21BEC263   
**University:** KLE Technological University, Hubballi-31  
**Portfolio domain:** Youtube   

## Introduction
<p align="center">
  <img src="https://github.com/codedmachine111/APS/assets/88738817/acd3df2e-42ba-45bf-961a-3bc00530d6fd" width="300" alt="HLD-Youtube">
</p>

YouTube is the world's largest video-sharing platform and operates on a very complex technological infrastructure. With over 2 billion monthly active users, more than 500 hours of videos are posted to YouTube every minute. Daily views of YouTube Shorts, a feature for short video content, are 15 billion. YouTube launched a $100 million Shorts Fund to entice Creators to experiment with producing short-form videos. Approximately 30,000 hours of video are uploaded to YouTube every hour by artists. Every week, 92% of internet users watch some form of YouTube video. YouTube also has the second-largest search engine in the world. Branded searches make up 52% of the top 100 queries. Leading countries based on YouTube audience size are the US, India, Japan, and Indonesia.

The smooth experience that users and creators enjoy is possible due to a variety of data structures and algorithms working under the hood. These technologies ensure efficient data management, personalized recommendations, optimized streaming, and much more. This portfolio explores the critical role of various data structures and algorithms that can potentially enhance YouTube's features and functionalities. By examining existing and potential use cases for these technologies, this portfolio aims to provide a comprehensive understanding of their impact on the platform.

### Objectives
- Categorize features and underlying technologies of YouTube.
- Identify key algorithms, data structures, or system design techniques currently in use or with potential applications in enhancing YouTube's features.
- Create a resource that can be used for educational purposes to understand the intersection of data structures, algorithms, and real-world applications in a large-scale platform like YouTube.

### Journey of the content

Let's explore the journey of a video from the creator to the viewer before we explore the business cases. There are three stakeholders in the content lifecycle: The **Creators** who record, edit, and upload videos; the **YouTube platform** where the video is uploaded and stored in the data centers; and finally, the **Viewers** who watch the video.
<p align="center">
  <img src="https://github.com/codedmachine111/APS/assets/88738817/71f5334c-f75f-4039-b623-0cce27331917" width="800" alt="HLD-Youtube">
</p>

Initially, when the creator tries to upload a video to YouTube, the file is directed to **Upload servers** that facilitate uploading the file from the client's device to a BLOB storage. After the video is uploaded and stored, they are fetched by the **Transcoding server** for processing and encoding the video to different bitrates and formats. The transcoded videos are distributed to Content Delivery Networks (CDNs) that are strategically and geographically placed. When the viewer starts streaming a video, they get the first segment of that video from the nearest CDN, and streaming protocols like MPEG-DASH help stream segments adaptively based on the viewer's network bandwidth.

### Business Use Cases

#### 1. Video Transcoding
Youtube handles more than 500 hours of video data being uploaded to it every minute. The time for processing these videos will significantly impact the latency and user experience. Transcoding is a computationally intensive operation that is done only once while uploading the videos. Compression algorithms like HEVC (High Efficiency Video Coding) can be used here to compress the video into multiple formats and resolutions. Huffman coding algorithm can be potentially used for compressing the significant amount of metadata like video duration, title, description, tags, subtitles etc. The uploaded video can be seperated into video and audio components and algorithms like AAC (Advanced Audio Coding) can be used to convert it audio into multiple formats and bitrates.

**Challenges**: Handling large video data, Efficient and fast video processing.

**Market Benefits**: Efficient data storage, Continuous playback on all devices.

**Design techniques and algorithms:**  
1. **Huffman coding:** Greedy technique
   - **Time Complexity:** O(nlog(n)) where n is number of unique characters.
   - **Space Complexity:** Linear [O(n)], for storing Huffman tree and encoded data.   
[View Implementation](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

#### 2. Directed Acyclic Graph (DAG) for transcoding pipeline
Different creators have different video processing requirements. Some might add a custom thumbnail, watermarks or upload a high definition video whereas others do not. Tu support these processing pipelines and maintain parallelism a DAG model can be used which defines tasks in stages so that they can be executed parallely or sequentially. These tasks can be scheduled using Topological sort.
**Challenges**: Allocation of available resources.

**Market Benefits**: Efficient resource management, Minimized cost.

**Design techniques and algorithms:**  
1. **Topological Sort for DAGs:** DFS based solution
   - **Time Complexity:** O(V+E) where V represents number of tasks and E represents the dependencies/ edges of DAG.
   - **Space Complexity:** O(V). The extra space is needed for the stack.

### References
- [YouTube Market Stats](https://www.simplilearn.com/youtube-marketing-stats-article)
