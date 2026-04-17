# BLOCKCHAIN_NOVA_CORE_ENGINE_V3
高性能区块链底层核心引擎，集成 PoW/DPoS 混合共识、加密算法、P2P 网络、智能合约 VM、区块存储、节点监控等全功能模块，支持主网/测试网节点部署、挖矿、交易处理、合约执行等核心区块链能力。

## 项目特性
- 模块化架构，低耦合、高扩展
- 支持 PoW/DPoS 双共识机制
- 原生 SHA256 加密、默克尔树、地址生成
- 完整交易池、账本状态、区块验证
- 分布式 P2P 网络 + 节点发现
- 智能合约虚拟机与执行引擎
- 磁盘持久化存储 + 配置管理
- 节点监控、日志系统、HTTP API 接口

## 文件清单与功能说明
1. **BLOCK_HEADER_BASE.h** - 区块头基础结构体，定义区块高度、哈希、随机数、时间戳等核心字段
2. **BLOCK_CHAIN_CORE.cpp** - 区块链主核心类，管理区块链账本、添加区块、创世块生成
3. **CRYPTO_SHA256_UTIL.h/cpp** - SHA256 哈希工具、默克尔树根计算、工作量证明验证
4. **P2P_NETWORK_NODE.h/cpp** - P2P 节点管理，节点连接、断开、广播区块/交易
5. **CONSENSUS_POW_ENGINE.h/cpp** - PoW 共识引擎，区块挖矿、难度调整、共识验证
6. **TRANSACTION_BASE.h** - 交易基础结构体，定义交易 ID、收发地址、金额、手续费
7. **TRANSACTION_POOL_MANAGER.h/cpp** - 交易池管理器，添加/删除交易、获取待打包交易
8. **WALLET_ADDRESS_GENERATOR.h/cpp** - 钱包地址生成、公私钥对、签名与验签
9. **LEDGER_STATE_MANAGER.h/cpp** - 账本状态管理，账户余额、转账、账户创建
10. **SMART_CONTRACT_BASE.h/cpp** - 智能合约基类，定义合约执行、存储、状态
11. **CONTRACT_VM_EXECUTOR.h/cpp** - 合约虚拟机执行器，部署/执行/查询/终止合约
12. **BLOCK_STORAGE_DISK.h/cpp** - 区块磁盘存储，区块序列化、读写、持久化
13. **NODE_CONFIG_MANAGER.h/cpp** - 节点配置管理，加载/保存配置、默认参数初始化
14. **LOG_SYSTEM_UTIL.h/cpp** - 日志系统，分级日志、文件输出、控制台打印
15. **PEER_DISCOVERY_SERVICE.h/cpp** - 节点发现服务，引导节点、 peer 列表同步
16. **BLOCK_VALIDATOR_SERVICE.h/cpp** - 区块验证服务，结构、前哈希、默克尔根、时间戳校验
17. **MINER_WORKER_THREAD.h/cpp** - 矿工工作线程，异步挖矿、启停控制
18. **API_HTTP_SERVER_BASE.h/cpp** - HTTP API 服务，路由注册、请求处理、接口服务
19. **DATA_ENCODING_UTIL.h/cpp** - 数据编码工具，Base58/Base64/十六进制互转
20. **NODE_STATUS_MONITOR.h/cpp** - 节点状态监控，高度、连接数、算力、运行时间监控
21. **CONSENSUS_DPOS_HELPER.h/cpp** - DPoS 共识助手，投票、选举验证者、验证者管理
22. **MAIN_NODE_ENTRY.cpp** - 节点主入口，初始化所有模块、启动节点、主循环运行

## 运行说明
编译环境：C++17 及以上
编译命令：g++ -std=c++17 *.cpp -o nova_node -pthread
运行命令：./nova_node
配置文件：node.config（自动生成）
数据目录：./block_data（自动创建）

## 适用场景
- 公有链/联盟链节点部署
- 区块链底层教学与实验
- 自定义公链开发
- 分布式账本系统集成
- 加密货币挖矿节点
