life-blog/
├── index.html          # 首页
├── post.html          # 文章详情页
├── about.html         # 关于我页面
├── css/
│   └── style.css      # 样式文件
├── js/
│   ├── main.js        # 主要逻辑
│   └── posts.js       # 文章数据
└── images/            # 图片资源

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>我的生活记录</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <nav class="navbar">
        <div class="container">
            <h1 class="logo">我的生活</h1>
            <ul class="nav-links">
                <li><a href="index.html">首页</a></li>
                <li><a href="about.html">关于我</a></li>
            </ul>
        </div>
    </nav>

    <main class="container">
        <section class="hero">
            <h2>记录生活，留住时光</h2>
            <p>这里是我的个人空间，记录生活中的点点滴滴</p>
        </section>

        <section class="posts-grid" id="postsContainer">
            <!-- 文章列表将通过 JavaScript 动态加载 -->
        </section>
    </main>

    <footer>
        <div class="container">
            <p>&copy; 2026 我的生活记录. All rights reserved.</p>
        </div>
    </footer>

    <script src="js/posts.js"></script>
    <script src="js/main.js"></script>
</body>
</html>

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>文章详情</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <nav class="navbar">
        <div class="container">
            <h1 class="logo">我的生活</h1>
            <ul class="nav-links">
                <li><a href="index.html">首页</a></li>
                <li><a href="about.html">关于我</a></li>
            </ul>
        </div>
    </nav>

    <main class="container">
        <article class="post-detail" id="postDetail">
            <!-- 文章内容将通过 JavaScript 动态加载 -->
        </article>
        <a href="index.html" class="back-link">← 返回首页</a>
    </main>

    <footer>
        <div class="container">
            <p>&copy; 2026 我的生活记录. All rights reserved.</p>
        </div>
    </footer>

    <script src="js/posts.js"></script>
    <script>
        const urlParams = new URLSearchParams(window.location.search);
        const postId = parseInt(urlParams.get('id'));
        const post = posts.find(p => p.id === postId);

        if (post) {
            document.title = post.title;
            document.getElementById('postDetail').innerHTML = `
                <h1>${post.title}</h1>
                <div class="post-meta">
                    <span class="date">${post.date}</span>
                    <span class="category">${post.category}</span>
                </div>
                <div class="post-content">
                    ${post.content}
                </div>
            `;
        } else {
            document.getElementById('postDetail').innerHTML = '<p>文章不存在</p>';
        }
    </script>
</body>
</html>

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>关于我</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <nav class="navbar">
        <div class="container">
            <h1 class="logo">我的生活</h1>
            <ul class="nav-links">
                <li><a href="index.html">首页</a></li>
                <li><a href="about.html">关于我</a></li>
            </ul>
        </div>
    </nav>

    <main class="container">
        <section class="about-section">
            <h1>关于我</h1>
            <div class="about-content">
                <p>你好，欢迎来到我的个人空间。</p>
                <p>这里记录着我的生活、思考和经历。</p>
                <p>希望通过文字，能够留住那些值得纪念的时刻。</p>
                
                <h2>联系方式</h2>
                <ul>
                    <li>邮箱: your-email@example.com</li>
                    <li>微信: your-wechat-id</li>
                </ul>
            </div>
        </section>
    </main>

    <footer>
        <div class="container">
            <p>&copy; 2026 我的生活记录. All rights reserved.</p>
        </div>
    </footer>
</body>
</html>

* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
    line-height: 1.6;
    color: #333;
    background-color: #f5f5f5;
}

.container {
    max-width: 1200px;
    margin: 0 auto;
    padding: 0 20px;
}

/* 导航栏 */
.navbar {
    background-color: #fff;
    box-shadow: 0 2px 4px rgba(0,0,0,0.1);
    padding: 1rem 0;
    position: sticky;
    top: 0;
    z-index: 100;
}

.navbar .container {
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.logo {
    font-size: 1.5rem;
    color: #2c3e50;
}

.nav-links {
    display: flex;
    list-style: none;
    gap: 2rem;
}

.nav-links a {
    text-decoration: none;
    color: #555;
    transition: color 0.3s;
}

.nav-links a:hover {
    color: #3498db;
}

/* 主要内容 */
main {
    min-height: calc(100vh - 200px);
    padding: 2rem 0;
}

/* 首页头部 */
.hero {
    text-align: center;
    padding: 3rem 0;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
    border-radius: 10px;
    margin-bottom: 3rem;
}

.hero h2 {
    font-size: 2.5rem;
    margin-bottom: 1rem;
}

.hero p {
    font-size: 1.2rem;
    opacity: 0.9;
}

/* 文章网格 */
.posts-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
    gap: 2rem;
    margin-bottom: 3rem;
}

.post-card {
    background: white;
    border-radius: 10px;
    padding: 1.5rem;
    box-shadow: 0 2px 8px rgba(0,0,0,0.1);
    transition: transform 0.3s, box-shadow 0.3s;
    cursor: pointer;
}

.post-card:hover {
    transform: translateY(-5px);
    box-shadow: 0 4px 16px rgba(0,0,0,0.15);
}

.post-card h3 {
    color: #2c3e50;
    margin-bottom: 0.5rem;
    font-size: 1.3rem;
}

.post-meta {
    display: flex;
    gap: 1rem;
    margin-bottom: 1rem;
    font-size: 0.9rem;
    color: #777;
}

.category {
    background-color: #3498db;
    color: white;
    padding: 0.2rem 0.6rem;
    border-radius: 4px;
    font-size: 0.85rem;
}

.post-excerpt {
    color: #666;
    line-height: 1.6;
}

/* 文章详情页 */
.post-detail {
    background: white;
    padding: 3rem;
    border-radius: 10px;
    box-shadow: 0 2px 8px rgba(0,0,0,0.1);
    margin-bottom: 2rem;
}

.post-detail h1 {
    color: #2c3e50;
    margin-bottom: 1rem;
    font-size: 2rem;
}

.post-content {
    margin-top: 2rem;
    line-height: 1.8;
    color: #444;
}

.post-content p {
    margin-bottom: 1rem;
}

.post-content h2 {
    margin-top: 2rem;
    margin-bottom: 1rem;
    color: #2c3e50;
}

.back-link {
    display: inline-block;
    color: #3498db;
    text-decoration: none;
    margin-bottom: 2rem;
    transition: color 0.3s;
}

.back-link:hover {
    color: #2980b9;
}

/* 关于页面 */
.about-section {
    background: white;
    padding: 3rem;
    border-radius: 10px;
    box-shadow: 0 2px 8px rgba(0,0,0,0.1);
}

.about-section h1 {
    color: #2c3e50;
    margin-bottom: 2rem;
}

.about-content p {
    margin-bottom: 1rem;
    line-height: 1.8;
}

.about-content h2 {
    margin-top: 2rem;
    margin-bottom: 1rem;
    color: #2c3e50;
}

.about-content ul {
    list-style: none;
    padding-left: 0;
}

.about-content li {
    padding: 0.5rem 0;
}

/* 页脚 */
footer {
    background-color: #2c3e50;
    color: white;
    text-align: center;
    padding: 2rem 0;
    margin-top: 3rem;
}

/* 响应式设计 */
@media (max-width: 768px) {
    .navbar .container {
        flex-direction: column;
        gap: 1rem;
    }

    .hero h2 {
        font-size: 1.8rem;
    }

    .posts-grid {
        grid-template-columns: 1fr;
    }

    .post-detail {
        padding: 1.5rem;
    }

    .about-section {
        padding: 1.5rem;
    }
}

// 这里存储所有文章数据
const posts = [
    {
        id: 1,
        title: "我的第一篇日记",
        date: "2026-04-20",
        category: "生活",
        excerpt: "今天是一个特别的日子，我决定开始记录自己的生活...",
        content: `
            <p>今天是一个特别的日子，我决定开始记录自己的生活。</p>
            <p>很多时候，我们会忘记那些看似平凡却珍贵的瞬间。通过文字，我希望能够留住这些记忆。</p>
            <h2>为什么要记录生活？</h2>
            <p>记录生活不仅仅是为了回忆，更是为了更好地认识自己。当我们回顾过去的文字时，会发现自己的成长轨迹。</p>
            <p>希望未来的自己，能够感谢现在坚持记录的我。</p>
        `
    },
    {
        id: 2,
        title: "周末的咖啡馆",
        date: "2026-04-22",
        category: "随笔",
        excerpt: "在一个安静的咖啡馆度过了一个下午，思考了很多事情...",
        content: `
            <p>周末的下午，我来到了一家安静的咖啡馆。</p>
            <p>窗外是熙熙攘攘的街道，而这里却像是一个与世隔绝的小天地。点了一杯拿铁，翻开一本书，时间就这样慢慢流淌。</p>
            <h2>关于慢生活</h2>
            <p>在快节奏的都市生活中，偶尔放慢脚步是一种奢侈。但正是这样的时刻，让我们能够重新审视自己的生活。</p>
            <p>咖啡的香气、书页的沙沙声、窗外的阳光，这些简单的元素构成了一个完美的下午。</p>
        `
    },
    {
        id: 3,
        title: "关于梦想的思考",
        date: "2026-04-25",
        category: "思考",
        excerpt: "最近一直在思考梦想这个话题，什么才是真正的梦想？...",
        content: `
            <p>最近一直在思考梦想这个话题。</p>
            <p>小时候，我们都有很多梦想。长大后，现实让我们不得不做出妥协。但这并不意味着我们要放弃梦想。</p>
            <h2>梦想与现实</h2>
            <p>梦想不一定要惊天动地，它可以是每天进步一点点，可以是坚持做自己喜欢的事情。</p>
            <p>重要的是，不要让生活的琐碎磨灭了内心的那份热情。</p>
            <p>今天，我决定重新审视自己的梦想，并为之努力。</p>
        `
    }
];

// 渲染文章列表
function renderPosts() {
    const container = document.getElementById('postsContainer');
    if (!container) return;

    container.innerHTML = posts.map(post => `
        <div class="post-card" onclick="location.href='post.html?id=${post.id}'">
            <h3>${post.title}</h3>
            <div class="post-meta">
                <span class="date">${post.date}</span>
                <span class="category">${post.category}</span>
            </div>
            <p class="post-excerpt">${post.excerpt}</p>
        </div>
    `).join('');
}

// 页面加载完成后执行
document.addEventListener('DOMContentLoaded', () => {
    renderPosts();
});
