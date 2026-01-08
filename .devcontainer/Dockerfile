# LTS (支持至 2030 年)
FROM ubuntu:20.04 
# LTS (支持至 2032 年)  
# FROM ubuntu:22.04  
# LTS (支持至 2034 年)
# FROM ubuntu:24.04     

# 避免在非交互模式下出现tzdata错误
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    build-essential \
    gdb \
    cmake \
    # 安装证书
    ca-certificates \   
    && rm -rf /var/lib/apt/lists/* 
    
#     python3-pip \
#     vim \
#     net-tools \
#     iputils-ping \


